class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& p: nums) {
            int remB=(1<<(__builtin_ctz(~p)))>>1;
            p^=(remB)|(-(remB==0) & ~p);
        }
        return move(nums);
    }
};