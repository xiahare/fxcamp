#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
const int N = 4;

struct Point {
    int x, y;

    // Define operator< for comparison
    bool operator<(const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

set<Point> diff1,diff0;
bool vis[N][N] = {};
int min_dist=INT_MAX;

void dfs(int dist){

    Point p1 = {-1,-1};
    for(auto p: diff1){
        if(!vis[p.x][p.y]){
            p1 = p;
        }
    }
    
    if(p1.x == -1 && p1.y==-1){
        min_dist = min(min_dist,dist);
    }
    
    vis[p1.x][p1.y] = true;

    for(Point p0: diff0){
        if(!vis[p0.x][p0.y]){
            vis[p0.x][p0.y] = true;

            dfs(dist + abs(p1.x-p0.x) + abs(p1.y-p0.y));

            vis[p0.x][p0.y] = false;
        }

    }
    
    vis[p1.x][p1.y] = false;
}


int main() {

    char a[N][N], b[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> b[i][j];
            
            if(a[i][j]!=b[i][j]){
                if(a[i][j]=='1'){
                    diff1.insert({i,j});
                } else {
                    diff0.insert({i,j});
                }
            }
        }
    }
    
    dfs(0);
    
    cout << min_dist << endl;
    return 0;
}

/**
1111
0000
1110
0010

1010
0101
1010
0101
-------
4
 
 
1100
1100
0011
0011

0011
0011
1100
1100
---------
12
---------
Details:
Need steps: 12
P1:(0,1) --> P0(0,2)
P1:(3,3) --> P0(0,3)
P1:(2,2) --> P0(1,2)
P1:(2,3) --> P0(1,3)
P1:(1,0) --> P0(2,0)
P1:(1,1) --> P0(2,1)
P1:(0,0) --> P0(3,0)
P1:(3,2) --> P0(3,1)
 
 
1110
1110
1100
0000

0001
0001
0011
1111
------
20
 
 */
