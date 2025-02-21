#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int p=0, q=0,cnt=0;
    
    while(p<n && q<m){
        if(abs(a[p]-b[q])<=k){
            cnt++;
            p++;
            q++;
        } else {
            if(a[p]>b[q]){
                q++;
            } else {
                p++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

/**
4 3 5
60 45 80 60
30 60 75

---------
2
 
 
 
10 10 0
37 62 56 69 34 46 10 86 16 49
50 95 47 43 9 62 83 71 71 7
--------------
1
 */
