class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]!=0){
            return 0;
        }
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
             return nums[i-1]+1;
            }
        }
      return nums.size();
    }
};