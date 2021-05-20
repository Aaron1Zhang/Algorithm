#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /*
    * @param k: An integer
    */Solution(int k) {
        // do intialization if necessary
        this->k = k;
        
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if(min_heap.size() < k) {
            min_heap.push(num);
        } else {
             if(num > min_heap.top()) {
                min_heap.pop();
                min_heap.push(num);
            }
            
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        auto heap_temp = min_heap;
        vector<int> res;
        while(!heap_temp.empty()) {
            res.insert(res.begin(),heap_temp.top());
            heap_temp.pop();
           
        }
        return res;
        // write your code here
    }
};