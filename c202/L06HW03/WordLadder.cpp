#include <iostream>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

bool isOneEditAway(const std::string& word1, const std::string& word2) {
    int len1 = (int)word1.size();
    int len2 = (int)word2.size();

    // Case 1: The lengths differ by more than one
    if (std::abs(len1 - len2) > 1) {
        return false;
    }

    int diffCount = 0;  // Counts the number of differences
    int i = 0, j = 0;   // Pointers for each word

    while (i < len1 && j < len2) {
        if (word1[i] != word2[j]) {
            if (diffCount == 1) {  // More than one edit needed
                return false;
            }
            diffCount++;

            // Check for insertion or deletion
            if (len1 > len2) {
                i++;  // Skip a character in word1
            } else if (len1 < len2) {
                j++;  // Skip a character in word2
            } else {
                i++;
                j++;  // Move both pointers for replacement
            }
        } else {
            // Move both pointers if characters match
            i++;
            j++;
        }
    }

    // Account for any extra character at the end of either word
    if (i < len1 || j < len2) {
        diffCount++;
    }

    return diffCount == 1;
}

bool handleQueue(int next_step, queue<string> &qa, vector<string> &wsa, map<string,int> &ma, map<string,int> &mb){
    
    queue<string> qt; // temporarily store the same step words
    
    while(!qa.empty()){
        auto t = qa.front();
        qa.pop();
        
        if(!wsa.empty()){
            for(auto it=wsa.begin(); it!= wsa.end();){
                //
                string& word = *it;

                
                if(isOneEditAway(t, word) && (ma.find(word)==ma.end()) ){
                    
                    if(! (mb.find(word) == mb.end()) ){
                        // exist in mb
                        cout << next_step + mb[word] << endl;
                        return true;
                    }
                    
                    qt.push(word); // temporarily store the same next_step words
                    
                    it = wsa.erase(it); // remove from wsa, don't check it later
                } else {
                    ++it; // move to next
                }
                
            }
        }
    }
    
    // all the next_step words
    while(!qt.empty()){
        string word = qt.front();
        qa.push(word);
        ma[word] = next_step;
        qt.pop();
    }
    
    return false;
}

int main() {
    // input
    string a, b;
    cin>>a;
    cin>>b;
    
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    
    int n;
    cin>>n;
    
    bool existB = false;
    int idxB=-1;
    vector<string> wsa(n);
    for(int i=0; i<n; i++){
        cin >> wsa[i];
        if(wsa[i]==b){
            idxB = i;
            existB = true;
        }
    }
    if(!existB){
        cout<<-1<<endl;
        return 0;
    }
    
    vector<string> wsb(wsa);
    wsb.erase(wsb.begin()+idxB); // remove b in wsb
    
    // init queue
    queue<string> qa,qb;
    map<string,int> ma,mb;
    qa.push(a);
    qb.push(b);
    ma[a] = 0;
    mb[b] = 0;
 
    // handle qa and qb
    int next_step=0;
    while(!qa.empty()&&!qb.empty()){
        next_step++;
        if(handleQueue(next_step,qa,wsa,ma,mb)){
            return 0;
        }
        if(handleQueue(next_step,qb,wsb,mb,ma)){
            return 0;
        }
    }
    
    cout<<-1<<endl;
    return 0;
}


/**
 
hello
world
5
hollo
worls
wollo
wolld
world
answer:
4
 
ac
ak
1
ak
answer:
1
 */
