class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negative;
        vector<int> positive;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
            else{
                positive.push_back(nums[i]);
            }
        }
        for(int k=0;k<positive.size();k++){
                ans.push_back(positive[k]);
                ans.push_back(negative[k]);
        }
        return ans;
    }
};