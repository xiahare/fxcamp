#include <iostream>
#include <queue>
using namespace std;

struct Point{
    int x,y;
    Point operator+ (Point other){
        return {x+other.x, y+other.y};
    }
    bool operator== (Point other){
        return x==other.x && y==other.y;
    }
};

vector<Point> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

bool inbound(Point &p, int &n, int &m){
    return p.x>=0 && p.x<n && p.y>=0 && p.y<m;
}

bool extendAdjacents(Point &t, const int &next_turn, Point &e, queue<Point> &q, int &n, int &m, vector<vector<int>> &v, vector<vector<char>> &maze){
    for(auto dir:dirs){
        Point np = t + dir;
        while( inbound(np,n,m) && v[np.x][np.y]==-1 && maze[np.x][np.y]=='0' ){
            if( np==e ){
                // end
                cout << next_turn << endl;
                return true;
            }
            
            q.push(np);
            v[np.x][np.y]=next_turn;
            
            // move to next straight point
            np = np + dir;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> maze(n,vector<char>(m,'0'));
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            cin >> maze[i][j] ;
        }
    }
    
    Point s,e;
    cin >> s.x >> s.y >> e.x >> e.y;
    
    // update index, due to input indexed from 1
    // need to change to be indexed from 0
    s.x--;
    s.y--;
    e.x--;
    e.y--;
        
    vector<vector<int>> v(n,vector<int>(m,-1));
    queue<Point> q;
    q.push(s);
    v[s.x][s.y]=0;
    
    if(extendAdjacents(s,0,e,q,n,m,v,maze)){
        return 0;
    }
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int next_turn = v[t.x][t.y] + 1;
        
        if(extendAdjacents(t,next_turn,e,q,n,m,v,maze)){
            return 0;
        }

    }
    
    cout << -1 << endl;
    return 0;
}

/**
5 7
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 1 0 1
0 1 1 0 0 0 0
0 0 0 0 1 1 0
1 3 1 7
------------
5
 */


/*
int dx[] = [0. 0. -1. 1};
int ydy] = [-1. 1. 0. 0};
 struct node{
 int s; int y; int steps; };
 
 void bfs(){
    q blahblahblah;
    while(!q.empty()){
        node cur = q.front();
        q.pop();
 if(is_finla()
 
        for (int i= 0; i<4; i++){
            //new node has the ++ on the direction respect to i
            nx = cur.x+dx[i];
            ny = cur.y+dy[i];
            nsteps = cur.steps+1;
            node newn = node{blah};
            while(is_valid(node new n){
                q.push(newn);
                //one step forward in the respective direction
 
                 nx = cur.x+dx[i];
                 ny = cur.y+dy[i];
                 nsteps = cur.steps+1;
                 node newn = node{blah};
 
 */
