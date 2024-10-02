#include <iostream>
#include <vector>
using namespace std;

bool inbound(int x, int y, int row, int col){
    if( x>=0&&y>=0&&x<row&&y<col ){
        return true;
    }
    return false;
}
void putWallIfPossible(int x, int y, int row, int col,vector<vector<char>> &maze){
    if( !inbound(x,y,row,col) ){
        return;
    }
    if( maze[x][y]=='G' || ( x==(row-1) && y==(col-1) /* Exit gate */ ) ){
        cout<<"NO"<<endl;
        exit(0);
    }
    
    if( maze[x][y]=='.' ){
        maze[x][y]='#';
    }
}
void bloodfill(int x, int y, int row, int col,vector<vector<char>> &maze,vector<vector<bool>> &visited){
    if( !inbound(x,y,row,col) || visited[x][y] || (maze[x][y]!='.' && maze[x][y]!='G') ){
        return;
    }
    
    visited[x][y] = true;
    bloodfill(x,y+1,row,col,maze,visited);
    bloodfill(x,y-1,row,col,maze,visited);
    bloodfill(x+1,y,row,col,maze,visited);
    bloodfill(x-1,y,row,col,maze,visited);
    
}

int main() {
    // read input
    int row, col;
    cin>>row>>col;
    vector<vector<char>> maze(row, vector<char>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>maze[i][j];
        }
    }

    // Turn into wall around B
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(maze[i][j]=='B'){
                // around
                putWallIfPossible(i,j+1,row,col,maze);
                putWallIfPossible(i,j-1,row,col,maze);
                putWallIfPossible(i+1,j,row,col,maze);
                putWallIfPossible(i-1,j,row,col,maze);
            }
        }
    }
    
    // Bloodfill , connect to Exit gate
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    bloodfill(row-1,col-1,row,col,maze,visited);
    
    string allescape = "YES";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(maze[i][j]=='G' && !visited[i][j]){
                allescape = "NO";
            }
        }
    }
    
    cout<<allescape<<endl;
    
    return 0;
}


/*
3 3
#B.
#..
GG.
 
Answer:
 YES
 
2 3
G.#
B#.

Answer:
NO

2 2
#B
G.
 
Answer:
NO
  
 */
