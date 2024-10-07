
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n,s;
    cin>>n>>s;
    int tmp;
    map<int,int> m;
    for (int i=1; i<=n; i++) {
        cin>>tmp;
        m[tmp]=i;
        auto it = m.find(s-tmp);
        if(it!=m.end()){
            cout<<it->second<< " "<< i <<endl;
            exit(0);
        }
    }

    std::cout << "No match found!\n"<<endl;

    return 0;
}

/*
4 8
2 7 5 1
 
answer:
2 4
 */
