class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
        long hash = 0;
        int m = key.size();
        for (int i = 0; i < m; ++i) {
            hash = (hash * 33 + key[i]) % HASH_SIZE;
        }
        
        return hash;
    }
};