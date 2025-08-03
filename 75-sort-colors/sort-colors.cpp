class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           ans.push_back(nums[i]);
        }
   
    }
};