#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001;

void dfs_weights(int node, vector<int> & weights, vector<vector<int>> & edges, vector<bool> & vis){
    vis[node] = true;
    for(auto x: edges[node]){
        if(!vis[x]){
            dfs_weights(x, weights, edges, vis);
            weights[node] += weights[x];
        }
    }
    
}

int main() {
    //freopen("/Users/lei/Downloads/test/uoj1.in", "r", stdin);
    
    int n;
    cin>>n;
    
    int edges_n = n-1;
    vector<vector<int>> edges(n+1,vector<int>());
    vector<bool> vis(n+1,false);
    vector<int> weights(n+1,1);
    
    while(edges_n--){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs_weights(1,weights,edges,vis);
    
    for(int i=1; i<n+1; i++){
        cout << weights[i]<< endl;
    }
    return 0;
}

/**
6
2 1
2 3
2 4
2 5
6 5
---------
6
5
1
1
2
1
 */
