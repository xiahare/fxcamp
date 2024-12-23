
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};
vector<Point> adjs = {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
bool valid(Point p, vector<vector<char>> & a, vector<vector<bool>> & vis, int n, int m){
    if(p.x>=0&&p.x<n&&p.y>=0&&p.y<m&&!vis[p.x][p.y]&&a[p.x][p.y]=='W'){
        return true;
    }
    return false;
}
void bfs(Point & p, vector<vector<char>> & a, vector<vector<bool>> & vis, int n, int m){
    queue<Point> q;
    q.push(p);
    vis[p.x][p.y]=true;
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for(auto adj: adjs){
            Point np = {curr.x+adj.x,curr.y+adj.y};
            if(valid(np, a, vis, n, m)){
                q.push(np);
                vis[np.x][np.y]=true;
            }
        }
    }
    
}

int main() {
    int n ,m ;
    cin >> n >> m;
    
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    
    int cnt=0;
    vector<vector<bool>> vis(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for (int j=0; j<m; j++) {
            Point p= {i,j};
            if(valid(p, a, vis, n, m)){
                cnt++;
                bfs(p, a, vis, n, m);
            }
            
        }
    }
    
    cout << cnt << endl;
    return 0;
}

/**
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
-------
3
 
10 10
....WW...W
..W...W...
.W........
W..W......
.W..W.WW..
W.........
.......W..
.W.......W
.W........
..W..W.W..
------------
10
 
20 15
..W.W.W......W.
......W.....W..
...W.....W....W
.WW.W.......W..
.......WW.....W
.W........W....
.......W.W...WW
.W....W......W.
.WW....W......W
........WW.W...
..WW.......W.W.
..........W...W
W.....WW..W....
...W...........
W...WW..W...W..
..W..W...W.....
........W.W....
......WW...W...
..WW......W.W..
W.........WWWW.
-----------
27
 */
