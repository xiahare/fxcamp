
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

struct Point{
    int x=0,y=0;
};
int main() {
    int n;
    cin >> n;
    vector<Point> ps(n);
    set<int> setx;
    set<int> sety;
    for(int i=0; i<n; i++){
        cin >> ps[i].x >> ps[i].y;
        setx.insert(ps[i].x);
        sety.insert(ps[i].y);
    }
    
    // compression
    unordered_map<int,int> mapx;
    unordered_map<int,int> mapy;
    int tmp_index = 1; // new index from 1
    for(auto& x: setx){
        mapx[x] = tmp_index++;
    }
    tmp_index = 1; // new index from 1
    for(auto& y: sety){
        mapy[y] = tmp_index++;
    }
    vector<vector<int>> psum(n+1,vector<int>(n+1,0));
    for( auto& p: ps){
        p.x = mapx[p.x];
        p.y = mapy[p.y];
        psum[p.x][p.y]=1;
    }
    
    // prepare psum
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            psum[i][j] = psum[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    // result
    ll cnt = 1+n; // for the case of empty set, 0 ; for the case of 1 item, n X 1 = n
    // for all [ Pi and Pj ] (i>j, avoid duplicate) , sum( left X right )
    for( int i=0; i<n; i++ ){
        Point& pi = ps[i];
        for( int j=i+1; j<n; j++ ){
            Point& pj = ps[j];

                int xmin = min(pi.x, pj.x);
                int ymin = min(pi.y, pj.y);
                int xmax = max(pi.x, pj.x);
                int ymax = max(pi.y, pj.y);
                // left: (1, ymin) -> (xmin, ymax)
                int left = psum[xmin][ymax] - psum[0][ymax] - psum[xmin][ymin-1] + psum[0][ymin-1];
                // right: (xmax, ymin) -> (n,ymax)
                int right = psum[n][ymax] - psum[xmax-1][ymax] -psum[n][ymin-1] + psum[xmax-1][ymin-1];
                cnt += left*right;

        }
    }
    
    cout << cnt << endl;
    return 0;
}

/**
4
0 2
1 0
2 3
3 5
----
13
 */

