
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    int a[n];
    deque<int> dq;
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(!dq.empty()&&a[i]<a[dq.back()]){ // asc or desc
            dq.pop_back();
        }
        dq.push_back(i);
        if(i+1>=m){
            while(!dq.empty() && dq.front()<i-m+1){
                dq.pop_front();
            }
            cout<<a[dq.front()]<<" ";
        }
    }
    
    std::cout << endl;
    return 0;
}

/**
7 3
3 5 4 6 8 1 2
answer:
3 4 4 1 1
 
 */
