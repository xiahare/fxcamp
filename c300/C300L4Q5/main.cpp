#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int,int>> a(n+1);
    a[0]={-1,0};
    for(int i=1; i<n+1; i++){
        int val;
        cin >> val;
        a[i] = {val,i};
    }
    sort(a.begin(),a.end());
    
    int p1=0,p2=0,p3=n;
    
    while(p1<n-1){
        p1++;
        p2 = p1+1;
        p3=n;
        int targetSum23 = x-a[p1].first;
        while(p2<p3){
            int sum23 = a[p2].first+a[p3].first;
            if(sum23==targetSum23){
                cout << a[p1].second << " " << a[p2].second << " " << a[p3].second << endl;
                return 0;
            } else if ( sum23<targetSum23 ){
                p2++;
                
            } else {
                p3--;
            }
        }
        
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/**
4 8
2 7 5 1
------
4 1 3
 
 
7 3
2 1 1 2 2 1 1
--------
2 3 7
 */
