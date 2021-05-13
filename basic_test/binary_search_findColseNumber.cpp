#include <iostream>
#include <vector>
using namespace std;

int closestNumber(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) {
            return -1;
        }
        int left = 0;
        int right = A.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left)/2;
            if(A[mid] < target) {
                left = mid;
            } else if(A[mid] >= target) {
                right = mid;
            } else {
                return mid;
            }
        }
       
        if(target - A[left] < A[right] - target) {
            return left;
        } else {
            return right;
        }
}

