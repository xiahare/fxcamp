#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int ASCII_A = (int)'A';

bool possible(int x,int y, vector<vector<char>> &maze, vector<bool> &visited, int row, int col){
    if(x>=0&&y>=0&&x<row&&y<col&&!visited[maze[x][y]-ASCII_A]){
        return true;
    }
    return false;
}

/**
  * &visited, &best_steps : will be changed in the function
  * other parameters are not
  */
bool bloodfill(int x,int y, vector<vector<char>> &maze, vector<bool> &visited, int row, int col, int& best_steps, int current_steps){
    if( !possible(x,y,maze,visited,row,col) ){
        return false;
    }
    
    int next_steps = current_steps + 1;
    visited[maze[x][y]-ASCII_A]=true;
    
    bool canGo = false;
    canGo = canGo || bloodfill(x+1,y,maze,visited,row,col,best_steps,next_steps);
    canGo = canGo || bloodfill(x-1,y,maze,visited,row,col,best_steps,next_steps);
    canGo = canGo || bloodfill(x,y+1,maze,visited,row,col,best_steps,next_steps);
    canGo = canGo || bloodfill(x,y-1,maze,visited,row,col,best_steps,next_steps);
    
    // backtracking
    visited[maze[x][y]-ASCII_A]=false;
    if( !canGo ){
        best_steps = max(current_steps,best_steps);
    }
    return canGo;
}
int main(){
    int row, col;
    cin>>row>>col;
    vector<vector<char>> maze(row, vector<char>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>maze[i][j];
        }
    }
    int mx_steps = 0;
    vector<bool> visitedAlpha(26, false);
    int sx=0,sy=0;
    int current_steps=1;
    bloodfill(sx,sy,maze,visitedAlpha,row,col,mx_steps,current_steps);
    // for all start cells
//    for(int i=0;i<row;i++){
//        for(int j=0;j<col;j++){
//            vector<bool> visitedAlpha(26, false);
//            int sx=i,sy=j;
//            int current_steps=1;
//            bloodfill(sx,sy,maze,visitedAlpha,row,col,mx_steps,current_steps);
//            
//        }
//    }
    
    cout << mx_steps << endl;
    
    return 0;
}


/**
3 6
HFDFFB
AJHGDH
DGAGEH

Answer:
6
 */
