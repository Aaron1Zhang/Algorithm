/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (SVNRepo::isBadVersion(left)) {
            return left;
        }
        return right;
    }
};