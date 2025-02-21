#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    
    auto bs = [&](int m) -> void {
        int l=1, r=n, mid, ans=0;
        while(l<r){
            mid = (l+r)/2;
            if(a[mid]<m){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l<=n && a[l]==m){
            ans = l;
        }
        cout << ans << " ";
        
    };
    
    int m;
    while ( cin >> m ){
        bs(m);
    }
    
    return 0;
}

/**
7
1 2 4 4 5 7 9
4 5 2 10

-------
3 5 2 0
 */
