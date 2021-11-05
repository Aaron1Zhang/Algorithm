class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> maps;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                auto sum = nums1[i] + nums2[j];
                if (maps.find(sum) != maps.end()) {
                    maps[sum] += 1;
                } else {
                    maps[sum] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                auto sum = -(nums3[i] + nums4[j]);
                if (maps.find(sum) != maps.end()) {
                    count += maps[sum];
                }
                   
            }
        }
        return count;

    }
};