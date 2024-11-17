#include <iostream>
#include <queue>
using namespace std;

struct Point{
    int x,y;
};

vector<Point> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
    int n,m;
    cin>>n>>m;
    
    Point ps, pg;
    vector<vector<char>> maze(n,vector<char>(m,'#'));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if( maze[i][j] == 'S'){
                ps.x = i;
                ps.y = j;
            } else if( maze[i][j] == 'G'){
                pg.x = i;
                pg.y = j;
            }
        }
    }
    
    queue<Point> q;
    vector<vector<int>> v(n,vector<int>(m,-1));
    q.push(ps);
    v[ps.x][ps.y]=0;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int next_step = v[t.x][t.y] + 1;
        
        for(auto dir: dirs){
            Point np = {t.x+dir.x,t.y+dir.y};
            if(np.x>=0 && np.x<n && np.y>=0 && np.y<m && maze[np.x][np.y]!='#' && v[np.x][np.y]==-1 ){
                if(maze[np.x][np.y]=='G'){
                    // end
                    cout << next_step << endl;
                    return 0;
                    
                }
                
                v[np.x][np.y] = next_step;
                q.push(np);
            }
        }
        
    }
    
    cout << -1 << endl;
    return 0;
}


/**
6 7
#S#####
#...#.#
#.#.#.#
#.#...G
#...#.#
#######
------------
8
 */
