#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    
    int n;
    cin>>n;
    
    int edges_n = n-1;
    vector<vector<int>> edges(n+1,vector<int>());

    vector<int> fathers(n+1,0);
    
    while(edges_n--){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    fathers[1]=-1; // root's father is -1
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x: edges[curr]){
            if(fathers[x]==0){
                fathers[x]=curr;
                q.push(x);
            }
        }
    }
    
    for(int i=2; i<n+1; i++){ // print from node 2
        cout << fathers[i]<< endl;
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
--------
1
2
2
2
5
 */
