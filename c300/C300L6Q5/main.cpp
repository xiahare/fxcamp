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
        int l=1, r=n+1, mid;
        while(l<r){
            mid = (l+r)/2;
            if(a[mid]<=m){
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        cout << l << " ";
        
    };
    
    int m;
    while ( cin >> m ){
        bs(m);
    }
    
    return 0;
}

/**
7
1 2 2 4 5 7 9
2 3 4 10

-------
4 4 5 8
 */
