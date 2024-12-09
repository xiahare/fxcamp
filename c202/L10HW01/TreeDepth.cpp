#include <iostream>

using namespace std;

int max_depth=0; // The root depth is 0
const int MAXN=1001;
char tr[MAXN][MAXN];

void dfs(int node, int dep, int n){
    max_depth= max(max_depth,dep);
    for(int i=0;i<n;i++){
        if( tr[node][i]=='1'){
            tr[node][i]='0';
            tr[i][node]='0';
            dfs(i,dep+1,n);
        }
    }
}
int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tr[i][j];
        }
    }
    
    int dep=1;
    dfs(0, 0, n);

    cout << max_depth << endl;
    return 0;
}

/**
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000
----------
4
 
 
 */
