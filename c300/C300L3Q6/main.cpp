#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    
    int VEC_LEN = n+1;
    char tmp_char;
    vector<vector<int>> psum(VEC_LEN, vector<int>(VEC_LEN,0));
    for(int i=1; i<VEC_LEN; i++){
        for (int j=1; j<VEC_LEN; j++) {
            cin >> tmp_char;
            psum[i][j] = (tmp_char=='*') + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    
    while (q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y1-1] -psum[x1-1][y2] + psum[x1-1][y1-1] << endl;
    }
    return 0;
}

/**
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
----
3
1
2
 */
