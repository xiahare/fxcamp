#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    int a;
    deque<int> dq;
    int curr_sum=0,mx_cnt=0;
    for(int i=0;i<n;i++){
        cin>>a;

        while(!dq.empty() && curr_sum+a>k){
            curr_sum=curr_sum-dq.front();
            dq.pop_front();
        }
        if(a<=k){
            dq.push_back(a);
            curr_sum=curr_sum+a;
            mx_cnt=max(mx_cnt,(int)dq.size());
        }

    }

    cout << mx_cnt << endl;
    return 0;
}


/**
5 5
3 2 1 2 3
answer：
3
 
5 5
3 2 1 2 7 3
answer：
3
 */
