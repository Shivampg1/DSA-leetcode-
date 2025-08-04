class Solution {
public:
    int dominantIndex(vector<int>& nums) {
          int max_val = -1;
    int max_index = -1;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > max_val) {
            max_val = nums[i];
            max_index = i;
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (i != max_index && max_val < 2 * nums[i]) {
            return -1;
        }
    }

    return max_index;

    }
};