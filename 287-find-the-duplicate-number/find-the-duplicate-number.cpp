class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0;
        int j=1;

        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i=j;
                j++;   
            }
            else{
            return nums[i];
            }
        }
        return -1;
    }
};