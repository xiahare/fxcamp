#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;
using ll = long long;
int main() {
    
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("testcases/q6t6.in",  "r", stdin);
    
    int n,a,b;
    cin >> n >> a >> b;
    
    vector<int> x(n);
    vector<ll> p(n+1,0); // p[0] = 0, sub_sum_x(i,j) = p[j+1] -p[i]
    ll res_max_sub = LLONG_MIN;
    for(int i=0;i<n;i++){
        cin >> x[i];
        p[i+1] = p[i] + x[i];
    }
    multiset<ll> ms; // {pi,...}
    // init
    int s=1,l=a, r=b; // l=s+a-1, r=s+b-1
    for(int i=a;i<=b;i++){
        if(i<=n){
            ms.insert(p[i]);
        }
    }
    res_max_sub = *ms.rbegin();
    
    // process
    while(true){
        s++;
        l=s+a-1;
        r=s+b-1;
        if(l>n&&r>n){
            break;
        }
        if(l-1>=1){
            ms.erase(ms.find(p[l-1])); // there was a bug here if ms.erase(p[l-1]), it will remove all p[l-1]
        }
        if(r<=n){
            ms.insert(p[r]);
        }
        res_max_sub = max(res_max_sub,*ms.rbegin() - p[s-1]);
        
    }
    
    cout << res_max_sub << endl;
    return 0;
}

/**
8 1 2
-1 3 -2 5 3 -5 2 2
----------
8
 
10 7 7
-22 0 78 -48 94 68 -7 -73 8 62
--------------
163
 
8 1 1
-1 3 -2 5 3 -5 2 2
------------
5
 
 
10 10 10
40 -83 63 34 58 47 98 -89 -82 4
---------------
90
 */
