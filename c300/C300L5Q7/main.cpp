#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto&i:a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    
    int l=0,r=0;
    int res_max_length1 = 0;
    int maxl=0,maxr=0;
    while(r<n){
        if(a[r]-a[l]<=k){
            if(r-l+1>res_max_length1){
                maxl=l;
                maxr=r;
                res_max_length1 = r-l+1;
            }
            r++;
        } else {
            l++;
        }
    }
    vector<int> b;
    for(int i=0;i<a.size();i++){
        if(i<maxl || i>maxr){
            b.push_back(a[i]);
        }
    }
    int l2=0,r2=0;
    int res_max_length2 = 0;

    while(r2<b.size()){
        if(b[r2]-b[l2]<=k){
            if(r2-l2+1>res_max_length2){

                res_max_length2 = r2-l2+1;
            }
            r2++;
        } else {
            l2++;
        }
    }
    
    cout << res_max_length1+res_max_length2 << endl;
    return 0;
}

/**
7 3
10
5
1
12
9
5
14

-----
5
 */
