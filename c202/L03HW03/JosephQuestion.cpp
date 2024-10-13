#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    deque<int> dq;
    for (int i=1; i<=n; i++) {
        dq.push_back(i);
    }
    int cnt=1;
    while (!dq.empty()) {
        if(cnt==m){
            cnt=1;
            cout<<dq.front()<<" ";
            dq.pop_front();
        }else{
            cnt++;
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    cout << endl;
    return 0;
}


/**
3 2
answer:
2 1 3
 */
