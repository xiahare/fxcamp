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
        while(l<=n){
            mid = (l+r)/2;
            if(a[mid]==m){
                while(mid-1>0&&a[mid-1]==m){
                    mid--;
                }
                ans = mid;
                break;
            } else if(a[mid]<m){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
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
