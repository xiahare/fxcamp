#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int pn=n-1, pm=m-1;
    ll d = 0;
    while(pn>=0){
        while(b[pm]>a[pn]){
            pm--;
        }
        d+= a[pn]-b[pm];
        pn--;
        pm--;
    }
    
    cout << d << endl;
    return 0;
}

/**
3 5
6 7 10
1 2 5 8 9
---------
7
 */
