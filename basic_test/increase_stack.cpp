#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//给定一个数组[3,4,2,7,5]
//输出 [-1,3,-1,2,2];
//输出数组中每个数左边小于该元素且离它最近的的元素

int main(int argc, const char** argv) {

    vector<int> arr{3,4,2,7,5};
    stack<int> s;
    for(int i = 0; i < arr.size(); ++i) {
        while(!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if(!s.empty()) {
            cout << s.top() << " ";
            s.push(arr[i]);  
        } else {
            cout << -1  << " ";
        }
       
        s.push(arr[i]);
    }
    return 0;
}