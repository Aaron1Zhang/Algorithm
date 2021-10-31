class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int start = 0, end = matrix[0].size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[left][mid] == target) {
                return true;
            } else if (matrix[left][mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (matrix[left][start] == target) {
            return true;
        }
        if (matrix[left][end] == target) {
            return true;
        }
        return false;

    }
};