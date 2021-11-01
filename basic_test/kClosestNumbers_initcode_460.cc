#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        int left = findLowerClosest(A, target, k); //找到小于target的最右边数
        int right = left + 1;
        vector<int> res;
        while (k--) {
            bool le = isLeftCloser(A, left, right, target);
            if (le) {
                res.push_back(A[left]);
                left--;
            } else {
                res.push_back(A[right]);
                right++;
            }
            
        }
        return res;
       
    }
    bool isLeftCloser(vector<int>& A, int left, int right, int target) {
        if (left < 0) return false;
        if (right >= A.size()) return true;
        return target - A[left] <= A[right] - target;
    }
    int findLowerClosest(vector<int> &A, int target, int k) {
        int left = 0;
        int right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                right = mid;
            } else if (A[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (A[right] < target) {
            return right;
        }
        if (A[left] < target) {
            return left;
        }
        return -1;
    }
};