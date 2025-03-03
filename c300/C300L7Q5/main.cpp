#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n,0);
    ll total=0;
    int min_a=INT32_MAX, max_a=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        total+=a[i];
        min_a = min(min_a,a[i]);
        max_a = max(max_a,a[i]);
    }
    int h = (total - m)/n;
    if( h<min_a) {
        cout << h << endl;
        return 0;
    }
    
    auto check = [&](int midh) -> bool {
        ll sum = 0;
        for(int i=0; i<n; i++){
            int delt = a[i] - midh;
            sum += delt>0?delt:0;
        }
        return sum>=m;
    };
 
    // BS
    int l=min_a,r=max_a;
    while(l<r){
        int mid = (l+r)/2;
        if(check(mid)){
            h = mid;
            l = mid+1;  // try out next mid+1
        } else {
            r = mid;
        }
    }
    cout << h << endl;
}

/**
5 20
4 42 40 26 46
--------
36
 */
