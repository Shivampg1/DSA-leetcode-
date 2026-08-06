class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int max_val=0;
        int zero=0;

        while(j<n){
            if(nums[j]==0) zero++;
            if(zero<=k){
                max_val=max(max_val,j-i+1);
                j++;
            }
            else if(zero>k){
                while(zero>k){
                    if(nums[i]==0) zero--;
                    i++;
                }
                j++;
            }
        }
        return max_val;

    }
};