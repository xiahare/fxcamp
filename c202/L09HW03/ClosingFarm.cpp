#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adjs(n+1); // indexed from 1
    for( int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    
    stack<int> s; // inverse
    for( int i=0; i<n; i++){
        int a;
        cin >> a;
        s.push(a);
    }
    
    vector<bool> v(n+1,false);
    vector<set<int>> groups;
    
    stack<string> results;
    
    while(!s.empty()){
        int item = s.top();
        s.pop();
        
        set<int> related_group_idx_nos;
        
        for(int node: adjs[item]){
            if(v[node]){
                // visited : record g_no
                for(int i=0; i<groups.size();i++){
                    auto g = groups[i];
                    if(g.find(node)!=g.end()){
                        // found
                        related_group_idx_nos.insert(i);
                        break;
                    }
                }
            }
        }
        
        if(related_group_idx_nos.size()>=1){
            int smallest = *related_group_idx_nos.begin(); // smallest group idx
            if(related_group_idx_nos.size()>1){
                // merge groups via related_group_idx_nos [ n-1,n-2...,1 to 0 ]
                for(auto it = related_group_idx_nos.rbegin(); it != related_group_idx_nos.rend(); ++it){ // large to small
                    int g_idx = *it;
                    if(smallest!=g_idx){
                        groups[smallest].insert(groups[g_idx].begin(), groups[g_idx].end());
                        groups.erase(groups.begin() + g_idx); // remove in group after merge
                    }
                }
            }
            // merge current item to "smallest group idx" group too
            groups[smallest].insert(item);
        } else {
            // newnodes is a new group
            set<int> newnodes = {item};
            groups.push_back(newnodes);
        }
        
        if(groups.size()==1){
            results.push("YES");
        } else {
            results.push("NO");
        }
        
        v[item] = true;
    }
    
    while (!results.empty()) {
        cout << results.top() << endl;
        results.pop();
    }
    return 0;
}

/**
4 3
1 2
2 3
3 4
3
4
1
2
-----
YES
NO
YES
YES

 
 */
