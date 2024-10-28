
#include <iostream>
#include <queue>

using namespace std;

vector<int> dirs = {1,-1};
struct record{
    int step;
    bool visited=false;
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> ki(n+1,0);
    for(int i=1; i<=n ; i++){
        cin >> ki[i];
    }
    
    int endchar;
    cin >> endchar; // 0
    
    queue<int> q;
    vector<record> r(n+1);
    q.push(a);
    r[a]={0,true};
    
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        
        for(auto dir: dirs){

            int next_floor = t + ki[t] * dir;
            int next_step = r[t].step + 1;
            if(next_floor==b){
                // destination
                cout<<next_step<<endl;
                return 0;
                
            }
            if( next_floor>0 && next_floor<=n && !r[next_floor].visited ){
                q.push(next_floor);
                r[next_floor]={next_step,true};
            }
        }
    }
    
    
    // no way
    cout << -1 << endl;
    return 0;
}

/**
5 1 5
3 3 1 2 5
0

answer:
3
 */
