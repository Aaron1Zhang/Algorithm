class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) {
            return ' ';
        }
        unordered_map<char, int> counts;
        for (auto& c: s) {
            counts[c]++;
        }
        for (auto& c: s) {
            if (counts[c] == 1) {
                return c;
            }
        }
        return ' ';

    }
};