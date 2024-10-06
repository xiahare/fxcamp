
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin>>n;
    int tmp;
    set<int> s;
    
    for(int i=0;i<n;i++){
        cin>>tmp;
        s.insert(tmp);
    }
    

    
    std::cout << s.size();
    return 0;
}

/**
5
2 3 2 2 3

answer:
2
 */
