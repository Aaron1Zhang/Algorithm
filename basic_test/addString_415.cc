class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> vec1, vec2;
        string s;
        for (int i = num1.size() - 1; i >= 0; --i) {
            vec1.push_back(num1[i] - '0');
        }

        for (int i = num2.size() - 1; i >= 0; --i) {
            vec2.push_back(num2[i] - '0');
        }

        int t = 0, i = 0;
        vector<int> res;
        while (i < vec1.size() || i < vec2.size()) {
            if (i < vec1.size()) {
                t += vec1[i];
            }
            if (i < vec2.size()) {
                t += vec2[i];
                
            }
            res.push_back(t % 10);
            t = t / 10;
            ++i;
        }
        if (t) {
            res.push_back(t);
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            s.push_back(res[i]+'0');
        }
        
        return s;

    }
};