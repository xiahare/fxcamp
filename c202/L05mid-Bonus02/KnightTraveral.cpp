
#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Point{
    int x,y;
};

vector<Point> dirs={{-2,-1},{-1,-2},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

int main() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int ax=x-1,ay=y-1;
    vector<vector<int>> res(n,vector<int>(m,-1));
    queue<Point> q;
    q.push({ax,ay});
    res[ax][ay]=0;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int next_step = res[t.x][t.y]+1;
        
        for(auto dir:dirs){
            Point newP = {t.x+dir.x,t.y+dir.y};
            
            //valid
            if(newP.x>=0 && newP.x<n && newP.y>=0 && newP.y<m && res[newP.x][newP.y]==-1){
                res[newP.x][newP.y]=next_step;
                q.push(newP);
            }
        }
        
    }
    
    for(int i=0; i<n; i++){
        
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**
 
3 3 1 1

Answer:
0    3    2
3    -1   1
2    1    4
 */
