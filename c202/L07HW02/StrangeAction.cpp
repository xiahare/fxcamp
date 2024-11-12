
#include <iostream>
#include <queue>
#include <map>

using namespace std;

vector<int> options(2,0);

int main(int argc, const char * argv[]) {
    int start, end;
    cin>> start >> end;
    
    if(start==end){
        cout<<0<<endl;
        return 0;
    }
    
    cin>> options[0] >> options[1];
    
    queue<int> q;
    map<int, int> m;
    q.push(start);
    m[start]=0;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int next_step = m[t]+1;
        
        for(int i=0; i<2; i++){
            int newPrice = t - options[i];
            if( newPrice==end ){
                // end
                cout << next_step << endl;
                return 0;
            }
            if( newPrice>end && m.find(newPrice)==m.end() ){
                q.push(newPrice);
                m[newPrice]=next_step;
            }
        }
    }
    
    cout<<-1<<endl;
    return 0;
}

/**
10 3
2 3
-------
3
 
 */
