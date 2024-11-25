#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int rel[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> rel[i][j];
        }
    }
    
    vector<bool> v(n,false);
    int friends = 0;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(!v[i]){
            q.push(i);
            v[i]=true;
            friends++;
            while(!q.empty()){
                int item = q.front();
                q.pop();
                for(int j=0; j<n; j++){
                    if(!v[j] && rel[item][j]==1){
                        q.push(j);
                        v[j]=true;
                    }
                }
            }
            
        }
    }
    
    cout << friends << endl;
    return 0;
}

/**
3
1 1 0
1 1 1
0 1 1
------
1
 
3
1 0 0
0 1 0
0 0 1
------
3
 */
