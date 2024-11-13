
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Point{
    int x,y;
    
    // Overload the < operator to define an order for Point objects
    bool operator<(const Point& other) const {
        // Define ordering, for example, by x-coordinate, then by y-coordinate
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }

    // Optionally, overload the == operator if needed
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

vector<Point> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

bool inboud(Point & p, int n, int m){
    if(p.x>=0 && p.x<n && p.y>=0 && p.y<m){
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>> maze(n,vector<char>(m,'#'));
    Point ph, py, pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='H'){
                ph = {i,j};
            } else if(maze[i][j]=='Y'){
                py = {i,j};
            } else if(maze[i][j]=='Q'){
                pq = {i,j};
            }
        }
    }
    
    queue<Point> qsh,qsy,qq;
    map<Point,int> msh,msy,mq;
    qsh.push(ph);
    qsy.push(py);
    qq.push(pq);
    msh[ph] = 0;
    msy[py] = 0;
    mq[pq] = 0;
    
    int next_step=0;
    bool endH=false, endY=false;
    int dHQ=-1,dYQ=-1;
    while( (!endH || !endY) && !qsh.empty() && !qsy.empty() && !qq.empty() ){
        
        next_step++;
        
        // for H
        queue<Point> qth;
        while( !endH && !qsh.empty() ){
            auto t = qsh.front();
            qsh.pop();
            
            for(auto dir: dirs){
                Point newP = {t.x+dir.x, t.y+dir.y};
                if(inboud(newP, n, m) && msh.find(newP)==msh.end() && maze[newP.x][newP.y]!='#'){
                    if( mq.find(newP)!=mq.end() ){
                        // exist
                        endH = true;
                        dHQ = next_step+mq[newP];
                        break;
                    } else {
                        msh[newP]=next_step;
                        qth.push(newP);
                    }
                }
            }
        }
        
        while ( !endH && !qth.empty()) {
            qsh.push(qth.front());
            qth.pop();
        }
        
        // for Y
        queue<Point> qty;
        while( !endY && !qsy.empty() ){
            auto t = qsy.front();
            qsy.pop();
            
            for(auto dir: dirs){
                Point newP = {t.x+dir.x, t.y+dir.y};
                if(inboud(newP, n, m) && msy.find(newP)==msy.end() && maze[newP.x][newP.y]!='#'){
                    if( mq.find(newP)!=mq.end() ){
                        // exist
                        endY = true;
                        dYQ = next_step+mq[newP];
                        break;
                    } else {
                        msy[newP]=next_step;
                        qty.push(newP);
                    }
                }
            }
        }
        
        while ( !endY && !qty.empty()) {
            qsy.push(qty.front());
            qty.pop();
        }
        
        // for Q
        queue<Point> qtq;
        while( (!endH || !endY) && !qq.empty() ){
            auto t = qq.front();
            qq.pop();
            
            for(auto dir: dirs){
                Point newP = {t.x+dir.x, t.y+dir.y};
                if(inboud(newP, n, m) && mq.find(newP)==mq.end() && maze[newP.x][newP.y]!='#'){
                    if( !endH && msh.find(newP)!=msh.end() ){
                        // H exists
                        endH = true;
                        dHQ = next_step+msh[newP];
                    } else if( !endY && msy.find(newP)!=msy.end() ){
                        // Y exists
                        endY = true;
                        dYQ = next_step+msy[newP];
                    }
                    
                    mq[newP]=next_step;
                    qtq.push(newP);
                    
                }
            }
        }
        
        while ( (!endH || !endY) && !qtq.empty()) {
            qq.push(qtq.front());
            qtq.pop();
        }
        
    }
    
    if( endH && endY ){
        cout<< dHQ+dYQ << endl;
    } else {
        cout<< "no way"<< endl;
    }
    return 0;
}


/**
 
8 10
#.##.Q.#.#
.#.#..###.
..#...#..#
.###......
#..Y..##.#
..#...#.#.
#.##.#####
.##.H..##.
-----------
14

8 10
#.##...#Q#
.#.#..###.
..#...#..#
.###......
#..Y..##.#
..#...#.#.
#.##.#####
.##.H..##.
------------
no way

 
 */
