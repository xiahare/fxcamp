#include <iostream>
#include <queue>
#include <map>

using namespace std;

bool handleQueue(queue<string> &qa, map<string, int> &ma, map<string, int> &mb, vector<string> &vai, vector<string> &vbi){
    int next_step;
    queue<string> tmpqueue;
    while(!qa.empty()){
        string t = qa.front();
        qa.pop();
        next_step = ma[t] + 1;
        
        // steps are larger than 10/2
        if(next_step>5){
            cout << "NO ANSWER!" << endl;
            return true;
        }
        
        for(int i=0; i<vai.size(); i++){
            auto ai = vai[i];
            auto bi = vbi[i];
            
            size_t pos = 0;
            while ((pos = t.find(ai, pos)) != string::npos) {
                string newStr = t; // Create a copy of the original string
                newStr.replace(pos, ai.length(), bi); // Replace once
                if(mb.find(newStr)!=mb.end()){
                    // exist in mb
                    cout << next_step + mb[newStr] << endl;
                    return true;
                }
                
                if(ma.find(newStr)==ma.end()){
                    // not exist in ma
                    tmpqueue.push(newStr); // temporarily store in tmpqueue for the same step
                    ma[newStr] = next_step;
                    
                }
                pos++; // Move to the next character after the current found position
                
            }
        }
    }
    
    // push to qa from tmpqueue after all the last steps are handled
    while (!tmpqueue.empty()) {
        auto tmp = tmpqueue.front();
        qa.push(tmp);
        tmpqueue.pop();
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    string a, b;
    cin>>a>>b;
    
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    
    vector<string> vai;
    vector<string> vbi;
    string ai, bi;
    while (cin>>ai>>bi){
        vai.push_back(ai);
        vbi.push_back(bi);
    }
    
    queue<string> qa,qb;
    map<string, int> ma,mb;
    qa.push(a);
    qb.push(b);
    ma[a] = 0;
    mb[b] = 0;
    

    while (!qa.empty()&&!qb.empty()) {

        if(handleQueue(qa, ma, mb, vai, vbi)){
            return 0;
        }
        
        if(handleQueue(qb, mb, ma, vbi, vai)){
            return 0;
        }
    }
    
    cout << "NO ANSWER!" << endl;
    return 0;
}


/**
abcd xyz
abc xu
ud y
y yz

answer:
3
 
((T+F)+(F+F))+(F+T) F
T+T F
T+F T
F+T T
F+F F
(T) T
(F) F

answer:
9
 
program procedure
g ce
ra dur
am ee
ee am
answer:
NO ANSWER!
 */
