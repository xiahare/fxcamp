#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    
    set<string> s;
    
        
    for(int len=1;len<=n;len++){
        s.clear();
        string sub ;
        for(int i=0;i<=n-len;i++){
            sub = str.substr(i,len);
            s.insert(sub);
        }
        if(s.size()==n-len+1){
            cout<< len << endl;
            exit(0);
        }
    }
    std::cout << n << endl;
    return 0;
}

/**
7
ABCDABC

answer:
4
 */
