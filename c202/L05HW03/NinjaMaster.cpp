
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct record{
    int step;
    bool visited=false;
};

int main() {
    int n;
    cin>>n;
    
    vector<int> ai(n+1);
    for(int i=1; i<=n; i++){
        cin>>ai[i];
    }
    
    queue<int> q;
    vector<record> rs(n+1);
    q.push(1);
    rs[1]={0,true};
    
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        
        int high_bound = t + ai[t];
        if(high_bound>1 && high_bound<=n){
            int start = ai[t]<0?1:t;
            int next_step = rs[t].step + 1;
            for(int i=start; i<=high_bound;i++){
                int next_log = i;
                
                if(next_log==n){
                    // destination
                    cout << next_step << endl;
                    return 0;
                }
                if(next_log>=1 && next_log<=n && !rs[next_log].visited ){
                    q.push(next_log);
                    rs[next_log] = {next_step,true};
                }
            }
        }
    }
    

    cout << -1 << endl;
    return 0;
}

/*
 
4
2 2 -1 2

answer:
2

2
-1 -2
answer:
-1
 
 */
