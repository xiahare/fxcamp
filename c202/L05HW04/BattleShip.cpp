
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point{
    int x,y;
};

vector<Point> move_adjacents = {{-1,0},{1,0},{0,-1},{0,1}}; // up down left right

void floodfill(int x, int y, vector<vector<char>> &a, vector<vector<bool>> & visited, int r, int c){
    // rectangle diagonal vertices
    int top=x, left=y, bottom=x, right=y;
    
    // mark visited adjacents
    queue<Point> q;
    q.push({x,y});
    visited[x][y]=true;
    
    while(!q.empty()){
        Point t = q.front();
        q.pop();
        
        for(auto move_adj: move_adjacents){
            int next_x = t.x + move_adj.x;
            int next_y = t.y + move_adj.y;
            
            if(next_x>=0 && next_x<r && next_y>=0 && next_y<c && a[next_x][next_y]=='#' && !visited[next_x][next_y]){
                q.push({next_x,next_y});
                visited[next_x][next_y]=true;
                
                // update diagonal vertices
                top = min(top, next_x);
                left = min(left, next_y);
                bottom = max(bottom, next_x);
                right = max(right, next_y);
                
            }
        }
    }
    
    // check diagonal
    bool rectangle = true;
    for(int i=top; i<=bottom; i++){
        for(int j=left; j<=right; j++){
            rectangle = rectangle && visited[i][j];
        }
    }
    if(!rectangle){
        cout << "Bad placement." << endl;
        exit(0);
    }
    
}

int main() {
    
    // input
    int r, c;
    cin >> r >> c;
    vector<vector<char>> a(r,vector<char>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
        }
    }

    // record info
    int cnt=0;
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    
    // floodfill for every cell
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j]=='#' && !visited[i][j]){
                
                floodfill(i,j,a,visited,r,c);
                cnt++;
            }
        }
    }
    
    cout << "There are " << cnt << " ships.";
    return 0;
}

/**
6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#
answer:
There are 5 ships.

6 8
......##
##.....#
##.....#
.......#
#......#
#..#...#
answer:
Bad placement.
 */
