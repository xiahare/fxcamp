
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while (q.size()>=2) {
        cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
        q.pop();
        
    }
    if(!q.empty()){
            cout<<q.front()<<endl;
    }
    
    return 0;
}


/**
5
answer:
1 3 5 4 2
 */
