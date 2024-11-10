
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    map<long,int> m;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        m[tmp]++;
    }
    
    for(auto x:m){
        cout<<x.first<< " " << x.second << endl;
    }
    return 0;
}


/**
9
2
4
6
2
6
4
2
8
6
Answer:
2 3
4 2
6 3
8 1
 */
