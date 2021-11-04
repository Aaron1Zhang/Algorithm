class TwoSum {
private:
    unordered_map<int, int> maps;
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        auto iter = maps.find(number);
        if (iter != maps.end()) {
            maps[number] += 1;
        }
        maps.insert({number, 1});
        
    }
    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        for (auto& p: maps) {
            auto v = p.first;
            auto c = p.second;
            if (value - v == v) {
                if (c >= 2) {
                    return true;
                }
            } else {
                if (maps.find(value - v) != maps.end()) {
                    return true;
                }
            }
            
        }
        return false;
        
    }
};