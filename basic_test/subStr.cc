class Solution {
public:
    const int BASE = 100000;
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        if (target.empty()) {
            return 0;
        }
        int pow = 1;
        int m = target.size();
        for (int i = 0; i < m; ++i) {
            pow = (pow * 31) % BASE;
        }

        int target_hash = 0;
        for (int i = 0; i < m; ++i) {
            target_hash = (target_hash * 31 + target[i]) % BASE;
        }

        int n = source.size();
        int source_hash = 0;
        for (int i = 0; i < n; ++i) {
            source_hash = (source_hash * 31 + source[i]) % BASE;
            if (i < m - 1) {
                continue;
            }

            if (i > m - 1) {
                source_hash = (source_hash - source[i-m] * pow) % BASE;
                if (source_hash < 0) {
                    source_hash += BASE;
                }
            }
            if (source_hash == target_hash) {
                if (source.substr(i - m + 1, m) == target) {
                    return i - m + 1;
                }
            }
        }
        return -1;
    }
};