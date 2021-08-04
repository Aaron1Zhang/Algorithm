#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1; 
        for(int i = 0; i <= haystack.size() - needle.size(); ++i) {
            int j = 0;
            int t = i;
            while((haystack[t] == needle[j]) && (j < needle.size())) {
                t++;
                j++;
            }
            if(j == needle.size()) return i;
        }
        return -1;

    }
};

int main(int argc, const char** argv) {
    Solution s;
    string a = "abc";
    string b = "c";
    auto i = s.strStr(a, b);
    cout << " i" << i << endl;
}