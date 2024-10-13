#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k,time_cnt=0;
    cin>>n>>k;
    int a[n];
    deque<int> dq;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        dq.push_back(i);
    }
    while(!dq.empty()){
        int idx = dq.front();
        a[idx] = a[idx] -1;
        time_cnt = time_cnt+1;
        dq.pop_front();
        if( idx==k && a[idx]==0 ){
            cout<<time_cnt<<endl;
            return 0;
        }
        if(a[idx]>0){
            dq.push_back(idx);
        }
        
    }
    return 0;
}

/**
 
4 0
4 1 1 1

answer:
7
 */
