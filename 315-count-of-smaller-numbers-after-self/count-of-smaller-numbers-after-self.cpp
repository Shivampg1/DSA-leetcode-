class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> sorted; // acts like our "two-pointer sorted list"

        for (int i = n - 1; i >= 0; i--) {
            // find insert position using binary search
            int pos = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            ans[i] = pos;

            // insert into sorted list to maintain order
            sorted.insert(sorted.begin() + pos, nums[i]);
        }
        return ans;
    }
};
