class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int char_count[256] = {0};
        int j = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size(); ++i) {
            while(j < s.size() && char_count[s[j]] == 0) {
                char_count[s[j]] = 1;
                ++j;
                if(j - i > ans)
                    ans = j - i;
            }
            if(j == s.size()) {
                break;
            }
            char_count[s[i]] = 0;
        }

        return ans;
    }
};