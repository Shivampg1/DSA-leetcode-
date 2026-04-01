class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        
        if(n==1) return true;
        int max_val=nums[0];
        int i=1;
        //int j;
        while(i<=max_val && i<n){
            if(max_val<nums[i]+i){
                max_val=nums[i]+i;
            }
            
            if(max_val>=n-1) {
                return true;
                break;
            }
            else{
                i++;
            }
        }
        // if(j!=n-1) {
        //     return false;
        // }
        return false;
    }
};