
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    string city ;
    string state;
    map<string,string> m;
    int pairs=0;
    for(int i=0;i<n;i++){
        cin>>city>>state;
        for(auto mit: m){
            if(mit.first.substr(0,2)==state && mit.second == city.substr(0,2) ){
                pairs++;
            }
        }
        m[city]=state;
    }
    std::cout << pairs << endl;
    return 0;
}

/**
6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL

answer:
1
 */
