#include <set>
#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    
    multiset<int> s;
    int h;
    for (int i=0; i<n; i++) {
        cin >> h;
        s.insert(h);
    }
    
    for(int i=0; i<m; i++){
        int t,ans=-1;
        cin >> t;
        auto it_upper = s.upper_bound(t);
        if(it_upper!=s.begin()){
            it_upper--;
            ans = *(it_upper);
            s.erase(it_upper);
        }
        cout << ans << endl;
    }
    return 0;
}

/**
5 3
5 3 7 8 5
4 8 3
---
3
8
-1
 */
