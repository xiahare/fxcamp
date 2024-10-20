
#include <iostream>
#include <queue>
using namespace std;

pair<int,int> neighbors[4] = {make_pair(-1,-1),make_pair(-1,0),make_pair(1,0),make_pair(1,1)};

int main() {
    int n, sx,sy;
    cin>>n>>sx>>sy;
    char maze[n][n];
    bool visisted[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            visisted[i][j]=false; // need to init false
        }
    }
    
    int cnt=0;
    
    queue<pair<int,int>> q;
    if(maze[sx][sy]=='0'){
        q.push(make_pair(sx,sy));
        visisted[sx][sy]=true;
        cnt++;
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        for(auto nb: neighbors){
            int x=nb.first+curr.first;
            int y=nb.second+curr.second;
            
            if(x>=0&&y>=0&&x<n&&y<n&&!visisted[x][y]&&maze[x][y]=='0'){
                q.push(make_pair(x,y));
                visisted[x][y]=true;
                cnt++;
            }
        }
        
    }

    
    
    cout << cnt << endl;
    return 0;
}


/**
3 0 0
0 0 0
0 1 0
1 0 1
 
Answer:
3
 */
