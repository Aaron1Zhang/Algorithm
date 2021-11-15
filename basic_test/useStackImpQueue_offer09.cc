#include <vector>
#include <stack>
#include <queue>
using namespace std;

class CQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (!stack2.empty()) {
            auto deleteValue = stack2.top();
            stack2.pop();
            return deleteValue;
        }
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (stack2.empty()) return -1;
        auto res = stack2.top();
        stack2.pop(); 
        return res;
    }
};


/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */