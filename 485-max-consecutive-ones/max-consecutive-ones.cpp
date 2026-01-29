class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty()) return -1;
        int count=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=1){
                count=0;
                i++;
            }
            else if(nums[i]==1){
               count++;
               ans.push_back(count);
                i++;
            }
            
        }
        if(ans.empty()) return 0;
        sort(ans.begin(),ans.end());
        int j=ans.size()-1;
        return ans[j];
    }
};