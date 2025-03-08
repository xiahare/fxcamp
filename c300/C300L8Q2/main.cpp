#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cow_cnt, grass_cnt;
    cin >> cow_cnt >> grass_cnt;
    vector<pair<int,int>> x(grass_cnt);
    
    for(auto &[a,b] : x){
        cin >> a >> b;
    }
    sort(x.begin(),x.end());
    
    int max_x = x[grass_cnt-1].second;
    
    auto success = [&] (int dist) -> bool {
        int cnt = 0, curr_grass=0, curr_cow=x[0].first;
        while( curr_cow <= max_x ){
            if( x[curr_grass].first <= curr_cow && curr_cow <= x[curr_grass].second ){
                cnt++;
                curr_cow = curr_cow + dist;
            } else {
                if(curr_cow>x[curr_grass].second){
                    curr_grass++;
                } else if(curr_cow<x[curr_grass].first) {
                    curr_cow = x[curr_grass].first;
                }
            }
            
        }
        return cnt>=cow_cnt;
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
0 2
4 7
9 9
--------
2
 
 */
