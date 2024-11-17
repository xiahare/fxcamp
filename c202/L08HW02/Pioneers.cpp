
#include <iostream>
#include <queue>

using namespace std;

struct Point{
    int x,y;
};

vector<Point> dirs = {{-1,0},{1,0},{0,-1},{0,1}};


int main() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    
    queue<Point> qa, qb;
    vector<vector<int>> v(n+1,vector<int>(m+1,-1)); // indexed from 1
    for( int i=0; i<a; i++){
        Point t;
        cin >> t.x >> t.y;
        qa.push(t);
        v[t.x][t.y] = 0;
    }
    for( int i=0; i<b; i++){
        Point t;
        cin >> t.x >> t.y;
        qb.push(t);
    }
    
    while(!qa.empty()){
        auto t = qa.front();
        qa.pop();
        int next_step = v[t.x][t.y] + 1;
        
        for( auto dir: dirs){
            Point np = {t.x+dir.x,t.y+dir.y};
            if(np.x>=1 && np.x<n+1 && np.y>=1 && np.y<m+1 && v[np.x][np.y]==-1 ){ // note: index and boundary
                v[np.x][np.y] = next_step;
                qa.push(np);
            }
        }
    }
    
    while(!qb.empty()){
        auto t = qb.front();
        qb.pop();
        cout << v[t.x][t.y] << endl;
    }
    return 0;
}

/**
5 4 2 3
1 1
5 4
3 3
5 3
2 4
----------
3
1
3
 */
