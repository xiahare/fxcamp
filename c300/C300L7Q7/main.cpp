#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;

int main() {

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n,0);
    double total_eff=0;
    ll min_a=INT32_MAX;
    for(int i=0; i<n; i++){
        cin >> a[i];
        total_eff+=1.0/a[i];
        min_a = min(min_a,a[i]);
    }
    ll max_h = m*min_a;
    ll min_h = floor(m/total_eff)<1?1:floor(m/total_eff);
    
    auto check = [&](ll h) -> bool {
        ll sum = 0;
        for(int i=0; i<n; i++){
            ll p = h / a[i] ;
            sum += p;
        }
        return sum>=m;
    };
 
    
    // BS
    ll l=min_h,r=max_h,h=r;
    while(l<=r){
        ll mid = (l+r)/2;
        if(check(mid)){
            h = mid;
            r = mid-1;  // try out next mid+1
        } else {
            l = mid+1;
        }
    }
    cout << h << endl;
}

/**
3 7
3 2 5
--------
8
 
1 1000000000
1
--------
1
 
1 1000000000
1000000000
---------
1000000000000000000
 
10 10
6 6 4 3 4 9 3 2 6 10
--------
6
 */
