#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, int> mSupIdx;
    
    for(int i=1; i<n+1 ; i++){
        int a;
        cin >> a;

        if(mSupIdx.find(m-a)==mSupIdx.end()){
            mSupIdx[a] = i;
        } else {
            cout << i << " " << mSupIdx[m-a];
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/**
4 8
2 7 5 1
------
4 2
 */
