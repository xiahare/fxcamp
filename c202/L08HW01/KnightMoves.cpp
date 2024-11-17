
#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x,y;
};

vector<Point> dirs={{-2,-1},{-1,-2},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

int main() {
    int n;
    cin >> n;
    Point ps, pe;
    cin >> ps.x >> ps.y;
    cin >> pe.x >> pe.y;
    
    queue<Point> q;
    vector<vector<int>> v(n,vector<int>(n,-1));
    q.push(ps);
    v[ps.x][ps.y] = 0;
    
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int next_step = v[t.x][t.y]+1;
        
        for(auto dir: dirs){
            Point np = {t.x+dir.x,t.y+dir.y};
            
            if( np.x>=0 && np.x<n && np.y>=0 && np.y<n && v[np.x][np.y]==-1 ){
                if(np.x == pe.x && np.y == pe.y){
                    // end
                    cout << next_step << endl;
                    return 0;
                }
                v[np.x][np.y] = next_step;
                q.push(np);
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}

/**
100
0 0
30 50
-------
28
 */
