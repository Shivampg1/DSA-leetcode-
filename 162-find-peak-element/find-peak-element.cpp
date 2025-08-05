class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }

        int maxIndex=0;

        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[maxIndex]){
                maxIndex=i;
            }
        }
        return maxIndex;
    }
};