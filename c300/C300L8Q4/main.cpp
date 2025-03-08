#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(auto &a : x){
        cin >> a;
    }
    
    auto success = [&] (int stage_cnt) -> bool {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<n;i++){
            if(q.size()>=stage_cnt){
                auto item = q.top();
                q.pop();
                q.push(item+x[i]);
            } else {
                q.push(x[i]);
            }
        }
        int last_t = 0;
        while (!q.empty()) {
            last_t = q.top();
            q.pop();
        }
        return last_t<=m;
    };
    
    int l=1, r=n+1;
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
5 8
4
7
8
6
4

-------
4
 */
