#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> val2index;
    vector<int> arr;
public:

    RandomizedSet() {
        // do intialization if necessary
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        if (val2index.find(val) == val2index.end()) {
            arr.push_back(val);
            val2index[val] = arr.size() - 1; 
            return true;
        }
        return false;
        
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        auto iter = val2index.find(val);
        if (iter == val2index.end()) {
            return false;
        }
        int index = iter->second;
        val2index.erase(arr[index]);
        arr[index] = arr.back();
        val2index[arr.back()] = index; 
        arr.pop_back();  
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        
        int ran_num=rand() % arr.size();
        return arr[ran_num];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */