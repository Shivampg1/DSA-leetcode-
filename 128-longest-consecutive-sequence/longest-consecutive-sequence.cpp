class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n=nums.size();
        if(n==1)return 1;
        int count=1;
        int max_val=0;
        for(int i=1;i<n;i++){
          if(nums[i]!=nums[i-1]+1){
            count=1;
          }
          else if(nums[i]==nums[i-1]+1){
            count++;
          }
            max_val=max(max_val,count);
        }
        return max_val;
    }
};