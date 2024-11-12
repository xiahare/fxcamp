
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    vector<int> mx(3,0);
    
    cin>>mx[0]>>mx[1]>>mx[2];
    
    // exit-1: first bottle is odd
    if(mx[0]%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    // exit-2: other two bottles are both less than half of 1st one
    int half = mx[0]/2;
    if(half>mx[1] && half>mx[2]){
        cout<<"NO"<<endl;
        return 0;
    }
    
    queue<vector<int>> q;
    map<vector<int>,int> m;
    vector<int> init = {mx[0],0,0};
    q.push(init);
    m[init]=0;
    
    
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int next_step = m[t]+1;
        
        for(int i=0; i<3; i++){
            
            for(int j=0; j<3; j++){
                
                if( i!=j ){
                    // not self
                    // poue wine : from i to j
                    int space = mx[j]-t[j];
                    if( t[i]>0 && space>0 ){
                        // t[i] has wine and t[j] has space
                        
                        // can pour
                        vector<int> newState = t; // copy from t
                        int change = min(t[i],space);
                        //  if t[i] wine > t[j] space,
                        // t[i] will remain and t[j] will full
                        //  if t[i] wine <= t[j] space
                        // t[i] will empty and t[j] will add the
                        newState[i] = t[i]-change;
                        newState[j] = t[j]+change;
                        
                        // check if end state
                        int cnt_half=0;
                        for(int k=0; k<3; k++){
                            if(newState[k]==half){
                                cnt_half++;
                            }
                        }
                        if(cnt_half==2){
                            cout<<next_step<<endl;
                            return 0;
                        }
                        
                        q.push(newState);
                        m[newState]=next_step;
                    }
                }
            }
        }
        
        
    }
    
    cout<< "NO" << endl;
    return 0;
}



/**
8 5 3
------
7

7 5 3
------
NO
 
11 5 3
------
NO
 */
