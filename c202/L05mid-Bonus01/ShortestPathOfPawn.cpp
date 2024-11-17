
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Point{
    int x,y;
    
    // Overload the < operator for Point comparison
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

vector<Point> dirs={{-1,0},{-2,0},{1,0},{2,0},{0,-1},{0,-2},{0,1},{0,2}};

bool handleQueueSucc(int & next_step, queue<Point>& qa, map<Point,int> &ma ,map<Point,int> &mb, int & n){
    
    queue<Point> qt;
    while(!qa.empty()){
        auto t = qa.front();
        qa.pop();
        
        for(auto dir: dirs){
            Point newP = {t.x+dir.x,t.y+dir.y};
                
            // in bound
            if( newP.x>=0 && newP.x<n && newP.y>=0 && newP.y<n){
                // not in ma
                if( ma.find(newP)==ma.end() ){
                    
                    // in mb
                    if(!(mb.find(newP)==mb.end())){
                        // success, exit
                        cout<<next_step+mb[newP]<<endl;
                        return true;
                    }
                    
                    ma[newP]=next_step;
                    qt.push(newP);
                }
                
                
            }
        }
    }
    
    while (!qt.empty() ) {
        auto t = qt.front();
        qa.push(t);
        qt.pop();
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    int n;
    int ax,ay,bx,by;
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    
    if(ax==bx && ay==by){
        cout<<0<<endl;
        return 0;
    }
    
//     // Method 1:
//    int deltx=bx-ax,delty=by-ay;
//    cout << "Method 1:" <<endl;
//    cout << (deltx/2+deltx%2 ) + (delty/2+delty%2 ) << endl;
//    cout << "Method 2:" <<endl;
     
     
    // Methed 2:
    queue<Point> qa,qb;
    map<Point,int> ma,mb;
    qa.push({ax,ay});
    qb.push({bx,by});
    ma[qa.front()]=0;
    mb[qb.front()]=0;
    
    int next_step=0;
    while(!qa.empty()&&!qb.empty()){
        next_step++;
        if(handleQueueSucc(next_step,qa,ma,mb,n)){
            return 0;
        }
        if(handleQueueSucc(next_step,qb,mb,ma,n)){
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
    
    
}

/**
100
0 0
1 1
Answer:
2
 
100
0 0
5 5
Answer:
6
 
100
0 0
5 8
Answer:
7
 
20
2 3
2 3
---------
0
 */
