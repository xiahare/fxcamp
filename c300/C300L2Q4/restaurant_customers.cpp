#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> cus(n*2);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        cus[2*i] = {a,1};
        cus[2*i+1] = {b,-1};
    }
    
    sort(cus.begin(),cus.end());
    
    int presum = 0 , max_sum = 0;
    for(int i=0; i<2*n; i++){
        presum = presum + cus[i].second;
        max_sum = max(presum,max_sum);
    }
    
    cout << max_sum;
    return 0;
}


/**
3
5 8
2 4
3 9
--------
2
 */
