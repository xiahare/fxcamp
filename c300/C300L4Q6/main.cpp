#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[10001]={};
    
    int max_a = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        arr[a-1]++;
        max_a = max(max_a,a);
    }
    int curr_cnt=0;

    for(int i=0; i<k+1; i++) {
        curr_cnt += arr[i];
    }
    
    int p1=0, p2=k;
    int max_cnt=curr_cnt;
    while( p2<max_a){
        p2++;
        curr_cnt = curr_cnt + arr[p2] - arr[p1];
        p1++;
        max_cnt = max( max_cnt, curr_cnt );
    }
    
    cout << max_cnt << endl;
    return 0;
}

/**
5 3
1
6
4
3
1
--------
 
4

 */
