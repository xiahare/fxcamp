#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    int max_x = 0;
    for(auto &a : x){
        cin >> a;
        max_x = max(max_x, a);
    }
    sort(x.begin(),x.end());
    
    auto success = [&] (int dist) -> bool {
        int cnt = 0;
        auto it = x.begin();
        while(it!=x.end()){
            cnt++;
            int idx = it - x.begin();
            it = lower_bound(it, x.end(), x[idx]+dist);
        }
        return cnt>=m;
    };
    
    int l=0, r=max_x+1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(success(mid)){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int ans = ( success(l-1) )? l-1 : 0 ;
    cout << ans << endl;
    return 0;
}

/**
5 3
1 2 8 4 9
-------
3
 */
