class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;

        while(s<=e){
            if(nums[s]<=nums[e]){
                return nums[s];
            }
            int mid=s+(e-s)/2;

            if(nums[mid]<=nums[mid+1] && nums[mid]<=nums[mid-1]){
                return nums[mid];
            }
            if(nums[s]<=nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return 0;
    }
};