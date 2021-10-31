class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        int left = 0;
        int right = 1;
        while (reader->get(right) < target) {
            left = right;
            right = 2*right;               
        }

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int mid_val = reader->get(mid);
            if (mid_val == target) {
                right = mid;
            } else if (mid_val < target) {
                left = mid;
            } else {
                right = mid;
            }

        }
        if (reader->get(left) == target) {
            return left;
        }
        if (reader->get(right) == target) {
            return right;
        }
        return -1;

    }
};