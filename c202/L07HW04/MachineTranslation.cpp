
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    int m,n;
    cin>>m>>n;
    
    queue<int> q;
    set<int> s;
    
    int tmp, lookups=0;
    for(int i=0; i<n; i++){
        cin>>tmp;
        
        if(s.find(tmp)==s.end()){
            // not exist, lookup
            lookups++;
            
            // remove if larger than M
            while( q.size()>=m ){
                s.erase(q.front());
                q.pop();
                
            }
            
            // put into cache
            q.push(tmp);
            s.insert(tmp);
        }
    }
    
    cout<<lookups<<endl;
    return 0;
}


/**
3 7
1 2 1 5 4 4 1
---------
5
 */
