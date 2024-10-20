
#include <iostream>
#include <queue>
using namespace std;

pair<int,int> neighbors[8] = {make_pair(-1,-1),make_pair(-1,0),make_pair(-1,1),make_pair(0,-1),make_pair(0,1),make_pair(1,-1),make_pair(1,0),make_pair(1,1)};

int main() {
    int n, m;
    cin>>n>>m;
    
    char maze[n][m];
    bool visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            visited[i][j]=false; // need to init false
        }
    }
    
    int cnt=0;
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&maze[i][j]=='1'){
                //the first water cell
                q.push(make_pair(i, j));
                visited[i][j]=true;
                cnt++;
                
                // mark visited around if water cell
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    
                    for(auto nb: neighbors){
                        int x=nb.first+curr.first;
                        int y=nb.second+curr.second;
                        
                        if(x>=0&&y>=0&&x<n&&y<m&&!visited[x][y]&&maze[x][y]=='1'){
                            q.push(make_pair(x,y));
                            visited[x][y]=true;
                        }
                    }
                }
            }

        }
    }
    
    cout << cnt << endl;
    return 0;
}


/**
 
5 5
10011
10010
11011
01000
11010
Answer:
3
 */
