#include <iostream>
#include <vector>
using namespace std;
//此二分查找是九章算法中的通用模板，其关键是：
//1、区间的判断，跳出循环后区间的数只保留一个或两个然后再判断和目标的关系
//2、找到目标后不退出，继续比较
//3、改模板设用于寻找第一个满足要求的数，如果寻找最后一个满足要求的数，
//将end = mid 改为end = start;
int binary_template(vector<int>& arr, int target) {
    auto start = 0;
    auto end = arr.size() - 1;
    while(start + 1 < end) {
        auto mid = start + (end - start) / 2;
        if(arr[mid] > target) {
            end = mid - 1;
        } else if(arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }

    }
    if(arr[start] == target) {
        return start;
    }
    if(arr[end] == target) {
        return end;
    }
    return -1;
}
int main(int argc, const char** argv) {
    vector<int> arr{1,2,3,4,4,5};
    auto pos = binary_template(arr, 1);
    cout << "the pos is at" << pos << endl;
    return 0;
}