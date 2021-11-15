class Solution {
public:
    // char findTheDifference(string s, string t) {
    //     unordered_map<char, int> maps;
    //     for (auto& c: s) {
    //         maps[c] += 1;
    //     }

    //     for (auto& c: t) {
    //         if (maps.count(c)) {
    //             if (--maps[c] == 0) {
    //                 maps.erase(c);
    //             }
    //             continue;
                
    //         }
    //         return c;
    //     }
    //     return 0;
    // }

    char findTheDifference(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t.back();
        
    }
};