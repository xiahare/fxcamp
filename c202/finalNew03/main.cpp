#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n = 10;
    cin >> n;
    
    vector<vector<int>> edges(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;
            if(c=='1'){
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(0); // root
    vis[0] = true;
    
    int width = 1;
    while(!q.empty()){
        queue<int> qt;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            for(auto adj: edges[x]){
                if(!vis[adj]){
                    qt.push(adj);
                    vis[adj]=true;
                }
            }
        }
        int currWidth = (int)qt.size();
        width = std::max(width,currWidth);
        q=qt;
    }
    
    cout << width << endl;
    return 0;
}

/**
 
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000
-----------
4
 */
