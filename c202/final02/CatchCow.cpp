#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    set<int> vis;
    queue<pair<int,int>> q;
    q.push({n,0});
    vis.insert(n);
    

    while(!q.empty()){
        auto x = q.front();
        q.pop();
        
        // next points
        set<int> ns;
        ns.insert(x.first-1);
        ns.insert(x.first+1);
        ns.insert(x.first*2);
        
        int step = x.second + 1;
        for(auto nx: ns){
            if(nx==k){
                cout << step << endl;
                return 0;
            }
            if( vis.find(nx)==vis.end() && nx>=0 && nx<=100000 ){
                q.push({nx,step});
                vis.insert(nx);
            }
        }
        
    }
    
    return 0;
}


/**
5 17
---
4
 */
