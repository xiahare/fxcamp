#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> d(n,0); // diff
    for(int i=0; i<k; i++ ){
        int a, b;
        cin >> a >> b;
        d[a]++;
        if(b+1<n){
            d[b+1]--;
        }
    }
    vector<int> p(n,0); // psum from diff
    p[0]=d[0];
    for(int i=1; i<n; i++ ){
        p[i]=p[i-1]+d[i];
    }
    sort(p.begin(),p.end());
    
    cout << p[n/2] << endl;
    return 0;
}

/**
7 4
5 5
2 4
4 6
3 5

-------
1
 */
