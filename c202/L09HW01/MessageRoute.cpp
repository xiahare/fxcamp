
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Memo{
    int step, lastNode;
};

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> adjs(n+1); // indexed from 1:  1,2,3,...,n
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    vector<Memo> memos(n+1,{-1,-1}); // 1,2,3,...,n
    queue<int> q;
    
    // start
    q.push(1);
    memos[1]={1,-1};
    
    while(!q.empty()){
        int item = q.front();
        q.pop();
        int next_step = memos[item].step + 1;
        
        for( auto & adj: adjs[item] ){

            if( memos[adj].step == -1 ){
                // not visited
                q.push(adj);
                memos[adj] = {next_step,item};
            }
            if (adj==n){
                // end when n
                cout << next_step<<endl;
                
                // output path
                stack<int> s;
                int last_node=n;
                while(last_node!=-1){
                    s.push(last_node);
                    last_node = memos[last_node].lastNode;
                }
                while(!s.empty()){
                    cout << s.top() << " ";
                    s.pop();
                }
                
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

/**
5 5
1 2
1 3
1 4
2 3
5 4
-----
3
1 4 5
 

10 20
8 9
6 7
9 10
7 9
3 4
5 8
6 8
1 2
5 7
8 10
2 3
1 4
7 8
5 6
6 9
1 3
4 5
3 6
3 5
7 10
-------
5
1 4 5 8 10
 */
