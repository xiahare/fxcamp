#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,k,b;
    cin >> n >> k >> b;
    
    vector<bool> v(n,false);
    for(int i=0; i<b; i++){
        int x;
        cin >> x;
        v[x-1]=true; // indexed from 1
    }
    // init
    int min_b, sub_b = 0 ;
    for(int i=0; i<k; i++){
        if(v[i]){
            sub_b++;
        }
    }
    min_b = sub_b;
    
    //process
    for(int r=k; r<n; r++){
        int l = r - k + 1;
        sub_b = sub_b - v[l-1] + v[r];
        min_b = min(min_b,sub_b);
    }
    
    cout << min_b << endl;
    return 0;
}

/**
10 6 5
2
10
1
5
9
------------
1
 */
