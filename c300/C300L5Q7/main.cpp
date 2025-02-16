#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto&i:a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    
    vector<int> preMax(n), win(n);
    int l=0,r=0;
    int maxl=0,maxr=0;
    while(r<n){
        if(a[r]-a[l]<=k){
            win[r] = max(win[r],r-l+1);
            r++;
        } else {
            l++;
        }
    }

    preMax[0] = win[0];
    for(int i =1; i<n ; i++){
        preMax[i] = max(preMax[i-1],win[i]);
    }
    
    int twoMax = 0;
    for(int i =1; i<n ; i++){
        int currWin = win[i];
        
        int preMaxWin = (i-currWin)<0? 0: preMax[i-currWin];
        
        twoMax = max( twoMax, currWin+preMaxWin);
        
        
    }
    
    
    cout << twoMax << endl;
    return 0;
}

/**
7 3
10
5
1
12
9
5
14

-----
5
 */
