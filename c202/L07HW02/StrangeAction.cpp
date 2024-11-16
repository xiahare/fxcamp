
#include <iostream>
#include <queue>

using namespace std;

vector<int> options(2,0);

int main() {
    int start, end;
    cin>> start >> end;
    
    if(start==end){
        cout<<0<<endl;
        return 0;
    }
    
    cin>> options[0] >> options[1];
    
    queue<int> q;
    q.push(start);
    int ways=0;
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        for(int i=0; i<2; i++){
            int newPrice = t - options[i];
            if( newPrice==end ){
                // end
                ways++;
                continue;
            }
            if( newPrice>end){
                q.push(newPrice);
            }
        }
    }
    
    cout<<ways<<endl;
    return 0;
}

/**
10 3
2 3
-------
3
 
200 100
20 30
-------
7
 
 
300000 100000
5000 9000
-------
102342019
 */
