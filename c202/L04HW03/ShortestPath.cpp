
#include <iostream>
#include <queue>
using namespace std;

pair<int,int> neighbors[4] = {make_pair(0,-1),make_pair(-1,0),make_pair(0,1),make_pair(1,0)}; // left up right down
struct searched_point{
    int x,y,level;
};
searched_point make_searched_point(int x,int y,int level){
    searched_point p;
    p.x = x;
    p.y = y;
    p.level = level;
    return p;
}
int main() {
    int n;
    cin>>n;
    char maze[n][n];
    bool visisted[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            visisted[i][j]=false; // need to init false
        }
    }
    
    queue<searched_point> q;
    if(maze[0][0]=='0'){
        q.push(make_searched_point(0,0,1));
        visisted[0][0]=true;
    }
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        for(auto nb: neighbors){
            int x=nb.first+curr.x;
            int y=nb.second+curr.y;
            int nextLevel =curr.level+1;
            
            if(x>=0&&y>=0&&x<n&&y<n&&!visisted[x][y]&&maze[x][y]=='0'){
                q.push(make_searched_point(x,y,nextLevel));
                visisted[x][y]=true;

                if(x==n-1&&y==n-1){
                    //destination
                    cout<<nextLevel<<endl;
                    return 0;
                    
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}


/**
3
0 0 0
1 0 1
0 0 0

Answer:
5
 
3
1 0 0
1 0 1
0 0 0

Answer:
-1
 */
