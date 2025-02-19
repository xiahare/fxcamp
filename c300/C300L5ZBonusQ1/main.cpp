#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n+1,0);
    vector<int> p(n+1,0);
    for(int i=1; i<n+1; i++){
        cin >> a[i];
        p[i] = p[i-1] + a[i];
    }
    
    int l=1, cntx=0;
    
    for(int r=1; r<n+1; r++){
        ll sub_sum = p[r] - p[l-1];
        while( sub_sum > x) {
            l++;
            sub_sum = p[r] - p[l-1];
        }
        if( sub_sum==x ){
            cntx++;
        }
    }
    
    cout << cntx << endl;
    return 0;
}

/**
5 7
2 4 1 2 7
-------
3
 */
