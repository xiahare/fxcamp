
#include <iostream>
#include <set>
using namespace std;

int main() {

    char ttt[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>ttt[i][j];
        }
    }
    
    set<set<int>> s_in_s;
    
    set<int> s;
    
    s.insert(ttt[0][0]);
    s.insert(ttt[0][1]);
    s.insert(ttt[0][2]);
    s_in_s.insert(s);
    
    s.clear();
    s.insert(ttt[1][0]);
    s.insert(ttt[1][1]);
    s.insert(ttt[1][2]);
    s_in_s.insert(s);
    
    s.clear();
    s.insert(ttt[2][0]);
    s.insert(ttt[2][1]);
    s.insert(ttt[2][2]);
    s_in_s.insert(s);
    
    s.clear();
    s.insert(ttt[0][0]);
    s.insert(ttt[1][0]);
    s.insert(ttt[2][0]);
    s_in_s.insert(s);
    
    s.clear();
    s.insert(ttt[0][1]);
    s.insert(ttt[1][1]);
    s.insert(ttt[2][1]);
    s_in_s.insert(s);
    
    s.clear();
    s.insert(ttt[0][2]);
    s.insert(ttt[1][2]);
    s.insert(ttt[2][2]);
    s_in_s.insert(s);
    
    
    s.clear();
    s.insert(ttt[0][0]);
    s.insert(ttt[1][1]);
    s.insert(ttt[2][2]);
    s_in_s.insert(s);
    
    
    s.clear();
    s.insert(ttt[0][2]);
    s.insert(ttt[1][1]);
    s.insert(ttt[2][0]);
    s_in_s.insert(s);
    
    int result1=0,result2=0;
    for(auto& sit: s_in_s){
        if(sit.size()==1){
            result1++;
        }
        if(sit.size()==2){
            result2++;
        }
        
    }
    
    cout<<result1<<endl;
    cout<<result2<<endl;
    
    return 0;
}


/**
COW
XXO
ABC
 
answer:
0
2
 
WWW
QWA
COQ
answer:
1
3
  
 */
