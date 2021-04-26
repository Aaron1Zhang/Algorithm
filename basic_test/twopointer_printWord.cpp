#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> printWord(string& s) {
    vector<string> result;
    if(s.empty()) {
        return result;
    }
    int i = 0;
    int j = 0;
    while(j < s.size()) {
        string word;
        while(j < s.size() && s[j] != ' ') {
            word.push_back(s[j]);
            j++;
        }
        i = j+1;
        j = i;
        result.push_back(word);
    }
    return result;
}

int main(int argc, const char** argv) {
    string s = "a cd wd";
    auto res = printWord(s);
    for(auto& s: res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}