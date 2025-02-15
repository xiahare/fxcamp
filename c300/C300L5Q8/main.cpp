#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
 
    int n;
    cin >> n;
    if(n==1){
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    for(auto&i:a){
        cin >> i;
    }
    sort(a.begin(),a.end());

    auto points = [&](int i, int j) -> int {
        return a[j]-a[i]+1;
    };
    auto blanks = [&](int i, int j) -> int {
        return a[j]-a[i]-1;
    };

    // min
    int l=0,r=0, win_cnt_max=0;
    while(r<n){
        int win_space = points(l,r);
        if( win_space <=n){ // win_space <= n, win_space= points(win_l,win_r), win_cnt=r-l+(win_space == n)

            win_cnt_max = max(win_cnt_max,r-l+1);
            r++;
        } else {
            l++;
        }
    }
    int res_min = n-win_cnt_max;
    // max
    int total_blanks = (points(0, n-1)-n);
    int lblanks = blanks(0, 1);
    int rblanks = blanks( n-2, n-1);
    int res_max = total_blanks - min( lblanks, rblanks ) ; // total_point_lenght -n -min(rblanks,lblanks) +1

    // min special cases
    if(total_blanks==0){
        res_min = 0;
    }else if(total_blanks==1){
        res_min = 1;
    }else if( total_blanks==lblanks || total_blanks==rblanks ){
        res_min = 2;
    }
    
    cout << res_min << endl;
    cout << res_max << endl;
    return 0;
}

/**
3
7
4
9
----
1
2

 (7)
5
8
7
6
5
2
--------
2
2
 
5
8
7
6
5
1000000000
-----------
2
999999991

 
(6)
5
8
7
6
5
10
----
1
1
 
(5)
5
100
101
104
102
103
-----
0
0
 */
