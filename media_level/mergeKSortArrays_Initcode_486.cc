class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        if (arrays.empty()) {
            return vector<int>{};
        }
        // write your code here
        int left = 0, right = arrays.size() - 1;
        return helper(arrays, left, right);
    }

    vector<int> helper(vector<vector<int>>& arrays, int left, int right) {
        if (left >= right) {
            return arrays[left];
        }
        int mid = left + (right - left) / 2;    
        auto leftRes = helper(arrays, left, mid);
        auto rightRes = helper(arrays, mid+1, right);
        return mergeTwoSortArray(leftRes, rightRes);
    }
    vector<int> mergeTwoSortArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int i = 0, j = 0;
        //int pos = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] <= B[j]) {
                res.push_back(A[i]);
                ++i;
            } else {
                res.push_back(B[j]);
                ++j;
            }

        }
        while (i < A.size()) {
            res.push_back(A[i]);
            ++i;
        }
        while (j < B.size()) {
            res.push_back(B[j]);
            ++j;
        }
        return res;
    }
};