#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> arr;
    void up(int index) {
        while(index > 1) {
            if(arr[index/2] < arr[index]) {
                swap(arr[index/2], arr[index]);
                index /= 2;
            } else {
                break;
            }
        }   
    }
    void down() {
        arr[1] = arr[arr.size()-1];
        arr.pop_back();
        int i = 1;
        while(2*i <= arr.size()-1) {
            int max_index = 2*i;
            if(max_index + 1 <= arr.size()-1) {
                max_index = arr[max_index] > arr[max_index+1]? max_index: max_index+1; 
            }
            if(arr[i] < arr[max_index]) {
                swap(arr[i], arr[max_index]);
                i = max_index;
            } else {
                break;
            }
        }
    }
public:
    Heap() = default;
    void buildHeap(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            push(nums[i]);
        }
    }
    int top() {
        if(arr.size() > 1)
            return arr[1];
        return -1;
    }
    void pop() {
        down();
    }
    void push(int t) {
        if(arr.empty()) {
            arr.resize(2);
            arr[0] = 0;
            arr[1] = t;
        } else {
            arr.push_back(t);
        }        
        up(arr.size()-1);
    }
};

int main(int argc, const char** argv) {
    Heap max_heap;
    vector<int> nums{0,1,2,3,4,5};
    max_heap.buildHeap(nums);
    cout << "max item is "  << max_heap.top() << endl;
    max_heap.pop();
    max_heap.pop();
    return 0;
}