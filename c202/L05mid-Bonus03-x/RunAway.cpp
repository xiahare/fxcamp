
#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x,y,z;
};

vector<Point> dirs = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

int execute(){
    int xn,yn,zn,limit;
    cin>>xn>>yn>>zn>>limit;
    
    vector<vector<vector<char>>> maze(xn, vector<vector<char>>(yn, vector<char>(zn, '1')));
    vector<vector<vector<int>>> ra(xn, vector<vector<int>>(yn, vector<int>(zn, -1)));

    for(int i=0; i<xn; i++)
        for(int j=0;j<yn;j++)
            for(int k=0;k<zn;k++){
                cin>>maze[i][j][k];
            }

    queue<Point> qa;
    qa.push({0,0,0});
    ra[0][0][0]=0;
    
    
    
    while(!qa.empty()){
        auto t = qa.front();
        qa.pop();
        int next_step=ra[t.x][t.y][t.z]+1;
        
        for(auto dir:dirs){
            Point newP = {t.x+dir.x,t.y+dir.y,t.z+dir.z};
            if(newP.x>=0 && newP.x<xn &&
               newP.y>=0 && newP.y<yn &&
               newP.z>=0 && newP.z<zn &&
               ra[newP.x][newP.y][newP.z]==-1 &&
               maze[newP.x][newP.y][newP.z]=='0'){
                
                // push into ra and temp queue, but not qa
                ra[newP.x][newP.y][newP.z] = next_step;
                qa.push(newP);
            }
        }
    }
    
    if(ra[xn-1][yn-1][zn-1]<=limit){
        cout<<ra[xn-1][yn-1][zn-1]<<endl;
    } else {
        cout<<-1<<endl;
    }
    
    return 0;
}
    
int main() {
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        
        execute();
    }
}
