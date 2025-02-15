#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    for (int &a:x) {
        cin >> a;
    }
    
    unordered_map<int,int> m; // <x,cnt>
    // init
    int l=0, r=0;
    m[x[0]] = 1;
    ll res=1;
    while(r<n-1){
        int rnext = r+1;
        if( m.find( x[rnext] )!=m.end() || m.size()<k ){
            // exist or size<k
            m[x[rnext]]++; // move right
            r++;
            res += rnext-l+1; // add window length
        } else {
            int lv = --m[x[l]];
            if(lv==0){
                m.erase(x[l]);
            }
            l++; // move left
        }
    }
    cout << res << endl;
    return 0;
}

/**
5 2
1 2 3 1 1
-------
10
 
 */
