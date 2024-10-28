
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int x, y;
};

vector<Point> adjs = {{-1,0},{1,0},{0,-1},{0,1}}; // up down left right
void floodfill(int x, int y, vector<vector<int>> &dis_grid, vector<vector<char>> &maze, int n, int m){
    queue<Point> q;
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    
    q.push({x,y});
    visited[x][y]=true;
    dis_grid[x][y]=0;
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int next_step = dis_grid[p.x][p.y]+1;
        
        for(auto adj: adjs){
            int n_x = p.x+adj.x;
            int n_y= p.y+adj.y;
            if(n_x>=0 && n_x<n && n_y>=0 && n_y<m && maze[n_x][n_y]!='#' && !visited[n_x][n_y]){
                dis_grid[n_x][n_y]=next_step;
                visited[n_x][n_y]=true;
                q.push({n_x,n_y});
            }
        }
    }
    
}

int main() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<char>> maze(n,vector<char>(m,'#'));
    int myx,myy,frx,fry;
    vector<Point> kfcs;
    for(int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j]=='@'){
                myx=i;
                myy=j;
            }
            if(maze[i][j]=='&'){
                frx=i;
                fry=j;
            }
            if(maze[i][j]=='F'){
                kfcs.push_back({i,j});
            }
            
        }
    }
    
    vector<vector<int>> my_dis_grid(n,vector<int>(m, INT_MAX));
    floodfill(myx,myy,my_dis_grid,maze,n,m);
    vector<vector<int>> fr_dis_grid(n,vector<int>(m, INT_MAX));
    floodfill(frx,fry,fr_dis_grid,maze,n,m);
    
    int best_dis = INT_MAX;
    for(auto kfc: kfcs){
        int x=kfc.x, y=kfc.y;
        best_dis = min(best_dis,my_dis_grid[x][y] + fr_dis_grid[x][y]);
    }
    std::cout << best_dis << endl;
    return 0;
}
/**
4 4
@.#F
....
.#..
F..&

answer:
6

4 4
&.#F
....
.#..
F#.@

answer:
8

 */

