#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            std::swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};

string reverseWords(string s) {
    int i = 0,j = 0;
    int size = s.size();
    while(j < size) {
        while(j < size && s[j] != ' ')
            ++j;
        auto t = j - 1;
        while(i < t) {
            swap(s[i], s[t]);
            ++i;
            --t;
        }
        ++j;
        i = j;
    }
    return s;
}

int main(int argc, const char** argv) {
    string s = "abc de erd e eree";
    auto res = reverseWords(s);
    cout << res << endl;
    return 0;
}