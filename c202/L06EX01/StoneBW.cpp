
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct DotStr{
    string str;
    int dot_pos;
};

bool validOnlyOneDot(char &x1, char &x2){
    return (x1=='.' && x2=='.') || (x1!='.' && x2!='.');
}

bool handleQueueSucc(int next_step, queue<DotStr>& qa, map<string, int>& ma, map<string, int>& mb, int m){
    
    queue<DotStr> qt;
    while(!qa.empty()){
        
        auto et = qa.front();
        qa.pop();
        
        string t = et.str;
        int dot_pos = et.dot_pos;
        for(int i=0;i<m-2;i++){
                // check
            if( i!=dot_pos && validOnlyOneDot(t[i], t[i+1]) ){
                    string newStr = t; // copy a new one

                    // swap
                    swap(newStr[i],newStr[dot_pos]);
                    swap(newStr[i+1],newStr[dot_pos+1]);
                    
                    // newStr not in ma
                    if( ma.find(newStr)==ma.end() ){
                        
                        // if newStr in mb, success
                        if(!(mb.find(newStr)==mb.end())){
                            cout<<next_step+mb[newStr]<<endl;
                            return true;
                        }
                        // push into temp queue
                        ma[newStr]=next_step;
                        qt.push({newStr,i});
                    
                    }
                }
        }
        
    }
    
    // push into qa and ma
    while(!qt.empty()){
        auto t = qt.front();
        qa.push(t);
        
        qt.pop();
    }
    
    return false;
}

int main() {
    int n;
    cin>>n;
    string a;
    string b;
    
    cin>>a;
    cin>>b;
    
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    int cntaB=0,cntbB=0;
    for(int i=0;i<n;i++){
        if(a[i]=='B')cntaB++;
        if(b[i]=='B')cntbB++;
    }
    if(n<=2||cntaB!=cntbB){
        cout << -1 << endl;
        return 0;
    }
    a.append("..");
    b.append("..");
    
    queue<DotStr> qa,qb;
    map<string, int> ma,mb;
    qa.push({a,n});
    qb.push({b,n});
    ma[a]=0;
    mb[b]=0;
    
    int next_step=0;
    while (!qa.empty()&&!qb.empty()) {
        next_step++;
        if(handleQueueSucc(next_step,qa,ma,mb,n+2)){
            return 0;
        }
        if(handleQueueSucc(next_step,qb,mb,ma,n+2)){
            return 0;
        }
        
    }
    
    cout << -1 << endl;
    return 0;
}

/**
6
BWBWBW
WWWBBB
answer:
4

6
BBBBBB
WWWWWW
answer:
-1

14
BBBWBWWWBBWWBW
WBWWBBWWWBWBBB
answer:
7
 
 */
