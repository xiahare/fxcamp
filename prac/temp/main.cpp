#include <iostream>
#include <string>
#include <vector>

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

int main() {
    string input = "saaaaabaaaa";
    string target = "aa";
    string replacement = "cc";

    vector<string> results = replaceOnce(input, target, replacement);

    // Output the results
    cout << "All possible replacements of \"" << target << "\" with \"" << replacement << "\":" << endl;
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
