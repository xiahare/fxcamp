//
//  main.cpp
//  01class
//
//  Created by Lei Xia on 10/13/24.
//

#include <iostream>
#include <vector>
using namespace std;

class param {
public:
    int count(){
        return (int)v.size();
    };
    void add(int val){
        v.push_back(val);
    }
    int sum(){
        int s=0;
        for(auto i: v){
            s += i;
        }
        return s;
    }
private:
    vector<int> v;
};

int main() {
    param p;
    p.add(100);
    p.add(500);
    p.add(700);
    
    std::cout << p.count() << " | " << p.sum()<< endl;
    return 0;
}
