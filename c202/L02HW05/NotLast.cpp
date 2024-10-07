
#include <iostream>
#include <map>
using namespace std;

bool cmp(pair<string,int> &p1, pair<string,int> &p2){
    return p1.second<p2.second;
}
int main() {
    int n;
    cin>>n;
    string tmpName;
    int tmpAmount;
    map<string, int> mstats;
    for(int i=0;i<n;i++){
        cin>> tmpName >> tmpAmount;
        mstats[tmpName] = mstats[tmpName] + tmpAmount;
    }
    vector<pair<string,int>> v;
    for(auto mit: mstats){
        v.push_back(make_pair(mit.first, mit.second));
    }
    
    sort(v.begin(),v.end(),cmp);
    
    int count = 0;
    string minName;
    if(v.size()<7){
        // some cows had no milk
        // the least min
        int minMilk=v[0].second;
        minName = v[0].first;
        for(auto p:v){
            if(minMilk==p.second){
                count++;
            }
        }

        
    } else {
        // all cows had milk
        // the second last min
        int minMilk=v[0].second;
        int min2Milk=0;
        int count = 0;
        for(auto p:v){
            if(minMilk!=p.second && min2Milk==0){
                min2Milk = p.second;
                minName = p.first;
            }
            if(min2Milk==p.second){
                count++;
            }
        }
        
    }
    if(count>1){
        // tie
        cout << "Tie" << endl;
    }else{
        // v[0].first
        cout << minName << endl;
    }
    return 0;
}

/**
 
10
Bessie 1
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Annabelle 10
Bessie 6
Henrietta 5

answer:
Henrietta
 
9
Bessie 1
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Bessie 6
Henrietta 5

answer:
Tie
 
8
Maggie 13
Elsie 3
Elsie 4
Henrietta 4
Gertie 12
Daisy 7
Bessie 6
Henrietta 5

answer:
Bessie
 */
