
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x,y,z;
};

vector<Point> dirs = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

bool handleQueueSucc(vector<vector<vector<int>>> &maze, int next_step, queue<Point> &qa, vector<vector<vector<int>>>& ra, vector<vector<vector<int>>>& rb, int &xn, int &yn, int& zn){
    queue<Point> qt;
    while(!qa.empty()){
        auto t = qa.front();
        qa.pop();
        
        for(auto dir:dirs){
            Point newP = {t.x+dir.x,t.y+dir.y,t.z+dir.z};
            if(newP.x>=0 && newP.x<xn &&
               newP.y>=0 && newP.y<yn &&
               newP.z>=0 && newP.z<zn &&
               ra[newP.x][newP.y][newP.z]==-1 &&
               maze[newP.x][newP.y][newP.z]==0){
                
                // success
                if(rb[newP.x][newP.y][newP.z]!=-1){
                    cout<<next_step+rb[newP.x][newP.y][newP.z]<<endl;
                    return true;
                }
                
                // push into ra and temp queue, but not qa
                ra[newP.x][newP.y][newP.z] = next_step;
                qt.push(newP);
            }
        }
    }
    
    while(!qt.empty()){
        qa.push(qt.front());
        qt.pop();
    }
    
    return false;
}

int execute(){
    
        int xn,yn,zn,limit;
        cin>>xn>>yn>>zn>>limit;
        
        vector<vector<vector<int>>> maze(xn,vector(yn,vector(zn,-1))),ra(xn,vector(yn,vector(zn,-1))),rb(xn,vector(yn,vector(zn,-1)));
        for(int i=0; i<xn; i++)
            for(int j=0;j<yn;j++)
                for(int k=0;k<zn;k++){
                    cin>>maze[i][j][k];
                }
        
        queue<Point> qa,qb;
        qa.push({0,0,0});
        qb.push({xn-1,yn-1,zn-1});
        ra[0][0][0]=0;
        rb[xn-1][yn-1][zn-1]=0;
        
        int next_step=0;
        while(!qa.empty()&&!qb.empty()){
            next_step++;
            if(limit%2==0&&next_step*2>limit){
                cout<<-1<<endl;
                return 0;
            }
            if(handleQueueSucc(maze,next_step,qa,ra,rb,xn,yn,zn)){
                return 0;
            }
            if(limit%2==1&&next_step*2>limit){
                cout<<-1<<endl;
                return 0;
            }
            if(handleQueueSucc(maze,next_step,qb,rb,ra,xn,yn,zn)){
                return 0;
            }
        }
        
        cout<<-1<<endl;
        return 0;
}
int main() {
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        
        execute();
    }
}

/**
1
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
Answer:
11
 
3
3 3 4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
3 3 4 10
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
3 3 4 11
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
Answer:
11
-1
11
 */
