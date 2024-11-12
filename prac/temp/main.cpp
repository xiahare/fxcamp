#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> replaceOnce(const string& str, const string& target, const string& replacement) {
    vector<string> results;
    size_t pos = 0;

    // Loop to find all occurrences of the target substring
    while ((pos = str.find(target, pos)) != string::npos) {
        string newStr = str; // Create a copy of the original string
        newStr.replace(pos, target.length(), replacement); // Replace once
        results.push_back(newStr); // Store the result
        pos++; // Move to the next character after the current found position
    }

    return results;
}

int remainer(int a, int p, int m){
    int n=1;
    for(int i=1;i<=p;i++){
        n=n*a;
        n = n%m;
    }
    return n;
}

int main() {
    
    std::string str = "AaBbDd";

    // 对字符串进行排序，确保从字典序第一个排列开始
    std::sort(str.begin(), str.end());

    int idx=1;
    // 输出所有的排列
    do {
        if( str.find("Ab")==string::npos && str.find("Ad")==string::npos &&
           str.find("Da")==string::npos && str.find("Db")==string::npos &&
           str.find("Ba")==string::npos && str.find("Bd")==string::npos &&
           str.find("bA")==string::npos && str.find("dA")==string::npos &&
              str.find("aD")==string::npos && str.find("bD")==string::npos &&
              str.find("aB")==string::npos && str.find("dB")==string::npos
           ){
            
            std::cout<< idx++ << ":" << str << std::endl;
        }
        
    } while (std::next_permutation(str.begin(), str.end()));


//    int cnt = 0;
//    int s1=0;
//    for(int i=36; i<=50; i++){
//        s1+=2*i-1;
//        cnt++;
//    }
//    int s2=0;
//    for(int i=1; i<=35; i++){
//        s2+=2*i-1;
//    }
//    cout<< "s1:"<< s1 << " | count: "<< cnt << endl;
//    
//    cout<< "s2:"<< s2<<endl;
    
//    for(int i=0;i<=200;i++){
//        cout<< i << " : " << remainer(i,100,125) << endl;
//    }

//    int n=1;
//    for(int i=1;i<19;i++){
//        n=n*7;
//        n = n%19;
//        cout << i << " : " << n << endl;
//    }

    
    
    return 0;
}

//int main() {
//    string input = "saaaaabaaaa";
//    string target = "aa";
//    string replacement = "cc";
//
//    vector<string> results = replaceOnce(input, target, replacement);
//
//    // Output the results
//    cout << "All possible replacements of \"" << target << "\" with \"" << replacement << "\":" << endl;
//    for (const auto& result : results) {
//        cout << result << endl;
//    }
//
//    return 0;
//}
