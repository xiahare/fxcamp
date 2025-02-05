#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    int max_x=1, max_y=1;
    vector<array<int,4>> a(n,{0,0,0,0});
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        for(int j=0;j<4;j++)a[i][j]++; // indexed from 1
        max_x = max(max_x,a[i][2]); // x2
        max_y = max(max_y,a[i][3]); // y2
    }
    
    int LEN_X = max_x+1; // avoid out of boundary
    int LEN_Y = max_y+1; // avoid out of boundary
    vector<vector<int>> diff(LEN_X, vector<int>(LEN_Y,0));
    // NOTE: range (close and open)
    for( auto& [x1,y1,x2,y2]:a){
        diff[x1][y1] += 1;
        diff[x1][y2] -= 1;
        diff[x2][y1] -= 1;
        diff[x2][y2] += 1;
    }

    int cnt = 0;
    // calculate psum,
    for(int i=1;i<max_x+1;i++){
        // cout << " ";
        for(int j=1;j<max_y+1;j++){
            // overwrite with psum
            diff[i][j] = diff[i][j] + diff[i][j-1] + diff[i-1][j] - diff[i-1][j-1];
            // cout << diff[i][j] << " ";
            if(diff[i][j]==k){
                cnt++;
            }
        }
        //cout << endl;
    }
    
    cout << cnt << endl;
    return 0;
}

/**
3 2
1 1 5 5
4 4 7 6
3 3 8 7
------
8
 */
