
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point{
    int x,y;
};

vector<Point> move_adjacents = {{-1,0},{1,0},{0,-1},{0,1}}; // up down left right

void floodfill(int x, int y, vector<vector<char>> &a, vector<vector<int>> &visited, int n,int seq,int &better_area,int &better_perimeter){
    
    // mark visited adjacents
    queue<Point> q;
    q.push({x,y});
    visited[x][y]=seq;
    
    while(!q.empty()){
        Point t = q.front();
        q.pop();
        
        for(auto move_adj: move_adjacents){
            int next_x = t.x + move_adj.x;
            int next_y = t.y + move_adj.y;
            
            if(next_x>=0 && next_x<n && next_y>=0 && next_y<n && a[next_x][next_y]=='#' && !visited[next_x][next_y]){
                q.push({next_x,next_y});
                visited[next_x][next_y]=seq;
                
            }
        }
    }
    
    // cal area and perimeter
    int area=0, perimeter=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]==seq){
                area++;
                
                for(auto move_adj: move_adjacents){
                    int adj_x = i + move_adj.x;
                    int adj_y = j + move_adj.y;
                    if(adj_x<0||adj_x>=n||adj_y<0||adj_y>=n){
                        // out of bound
                        perimeter++;
                    } else if(a[adj_x][adj_y]=='.'){
                        perimeter++;
                    }
                }

            }
        }
    }
    
    // update better
    if(better_area==area){
        better_perimeter = min(better_perimeter, perimeter);
    } else if (better_area<area){
        better_area = area;
        better_perimeter = perimeter;
    }
}

int main() {
    
    // input
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    // record info
    int seq=0, better_area=0, better_perimeter=INT_MAX;
    vector<vector<int>> visited(n,vector<int>(n,0));
    
    // floodfill for every cell
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]=='#' && visited[i][j]==0){
                seq++;
                floodfill(i,j,a,visited,n,seq,better_area,better_perimeter);
                
            }
        }
    }
    
    cout << better_area << " " << better_perimeter << endl;
    return 0;
}

/**
6
##....
....#.
.#..#.
.#####
...###
....##
answer:
13 22
 */
