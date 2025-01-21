#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> pre(n,vector<int>(3,0));
    for (int i=0; i<n; i++) {
        char c; // H - 0, P - 1, S - 2
        int a;
        cin >> c;
        if(c=='H'){
            a = 0;
        } else if(c=='P'){
            a = 1;
        } else {
            a = 2;
        }
        // prefix count
        if( i == 0 ){
            pre[i][a]++;
        } else {
            pre[i] = pre[i-1];
            pre[i][a] = pre[i-1][a] + 1;
        }
        
    }
    
    int max_win = 0;
    for (int i=0; i<n; i++) {
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                // 3*2: max (pre + post)
                if(j!=k){
                    max_win = max( max_win, pre[i][j] + (pre[n-1][k]-pre[i][k]) );
                }
            }
        }
    }
    
    cout << max_win;
    return 0;
}

/**
5
P
P
H
P
S
------
4
 */
