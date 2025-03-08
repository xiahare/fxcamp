#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    int max_x=0,sum_x = 0;
    for(auto &a : x){
        cin >> a;
        max_x = max(max_x,a);
        sum_x += a;
    }
    
    auto success = [&] (int sum_limit) -> bool {
        int cnt = 1, p=0, curr_sum=0;
        while(p<n){
            int next_sum = curr_sum + x[p];
            if( next_sum>sum_limit ){
                cnt++;
                curr_sum = x[p];
            } else {
                curr_sum = next_sum;
            }
            p++;
        }
        return cnt<=m;
    };
    
    int l=max_x, r=sum_x+1;
    while(l<r){
        int mid = l + (r-l)/2;
        if(success(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int ans = l;
    cout << ans << endl;
    return 0;
}

/**
5 3
4 2 4 5 1
-------
6
 */
