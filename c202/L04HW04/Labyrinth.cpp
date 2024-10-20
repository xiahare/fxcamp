
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct neighbor{
    int x,y;
    char s_dir;
};
neighbor make_neighbor(int x,int y,char s_dir){
    neighbor p;
   p.x = x;
   p.y = y;
   p.s_dir = s_dir;
   return p;
}
neighbor neighbors[4] = {make_neighbor(0,-1,'L'),make_neighbor(-1,0,'U'),make_neighbor(0,1,'R'),make_neighbor(1,0,'D')}; // left up right down
struct searched_point{
    int x,y,level,lx,ly;
    char s_dir;
    
};
searched_point make_searched_point(int x,int y,int level,int lx,int ly,char s_dir){
    searched_point p;
    p.x = x;
    p.y = y;
    p.level = level;
    p.lx = lx;
    p.ly = ly;
    p.s_dir = s_dir;
    return p;
}
int main() {
    int n, m;
    cin>>n>>m;
    
    int ax=-1,ay=-1; // A
    int bx=-1,by=-1; // B
    char maze[n][m];
    bool visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            visited[i][j]=false; // need to init false
            if(maze[i][j]=='A'){
                ax=i;
                ay=j;
            }
            if(maze[i][j]=='B'){
                bx=i;
                by=j;
            }
        }
    }
    
    queue<searched_point> q;
    searched_point searched_points[n][m];
    if(maze[ax][ay]=='A'){
        q.push(make_searched_point(ax,ay,0,-1,-1,' '));
        searched_points[ax][ay]=q.front();
        visited[ax][ay]=true;
    }
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int nextLevel =curr.level+1;
        int lx=curr.x;
        int ly=curr.y;
        
        for(auto nb: neighbors){
            int x=nb.x+curr.x;
            int y=nb.y+curr.y;
            
            // arrive 'B'
            if(x==bx&&y==by){
                // end
                cout<<"YES"<<endl;
                cout<<nextLevel<<endl;
                stack<char> s;
                s.push(nb.s_dir);
                auto tmp = curr;
                // inverse path with stack
                while(!(tmp.x==ax&&tmp.y==ay)){
                    s.push(tmp.s_dir);
                    tmp = searched_points[tmp.lx][tmp.ly];
                }
                // print path
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<endl;
                return 0;
                
            }
            
            if(x>=0&&y>=0&&x<n&&y<m&&!visited[x][y]&&maze[x][y]=='.'){
                auto tmp = make_searched_point(x,y,nextLevel,lx,ly,nb.s_dir);
                searched_points[x][y]=tmp;
                q.push(tmp);
                visited[x][y]=true;
            }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}


/**
5 8
########
#.A#...#
#.##.#B#
#......#
########

Answer:
YES
9
LDDRRRRRU
 */
