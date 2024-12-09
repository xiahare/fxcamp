#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    char tr[n][n];
    bool vis[n];
    int cnt[n];
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    
    for(int i=0; i<n; i++){
        //vis[i]=false;
        //cnt[i]=0;
        for(int j=0; j<n; j++){
            cin >> tr[i][j];
        }
    }

    queue<int> q;
    q.push(0);
    vis[0]=true;
    
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i=0; i<n; i++){
            if( tr[curr][i]=='1' && !vis[i] ){
                cnt[curr]++;
                q.push(i);
                vis[i]=true;
            }
        }
    }
    
    vector<int> vec;
    for(int i=0; i<n; i++){

        if(cnt[i]==0){
            vec.push_back(i+1) ;
        }
        
    }
    
    cout << vec.size() << endl;
    for(int i=0; i<vec.size(); i++){
        if(i!=0){
            cout << " ";
        }
        cout << vec[i];
    }

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
5
4 5 8 9 10
 */
