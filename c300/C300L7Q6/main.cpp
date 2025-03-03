#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("testcases/q6t6.in",  "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<double> a(n,0);
    double total=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        total+=a[i];
    }
    double max_h = total/m + 0.001;
    
    auto check = [&](double midh) -> bool {
        ll cnt = 0;
        for(int i=0; i<n; i++){
            int delt = a[i] / midh;
            
            cnt += delt;
        }
        return cnt>=m;
    };

    // BS
    double h=0.001,l=0.001,r=max_h;
    while(r-l>0.001){
        double mid = (l+r)/2;
        if(check(mid)){
            h = mid;
            l = mid;  // try out next
        } else {
            r = mid;
        }
    }

    double ans = floor((h+0.001) * 100)/100.0;
    if(check(ans+0.01)){
        ans += 0.01;
    }
    if(check(ans+0.01)){
        ans += 0.01;
    }
    cout << fixed << setprecision(2) << ans << endl;
}

/**
4 11
8.02 7.43 4.57 5.39
--------
2.00
 */
