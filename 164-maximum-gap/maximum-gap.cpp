class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int max_val=0;
        sort(nums.begin(),nums.end());
        if(nums.size() < 2){
            return 0;
        }
        int i=1;
        while(i<nums.size()){
            int val=(nums[i]-nums[i-1]);
            max_val=max(val,max_val);
            ++i;
        }
        return max_val;
    }
};