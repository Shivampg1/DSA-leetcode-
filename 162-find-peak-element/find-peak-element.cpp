class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
    if(n==1) return 0;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(mid>0 && mid<n-1){
                if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid+1]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            else{
                if(mid==0){
                    if(nums[mid]>=nums[mid+1]){
                        return mid;
                    }
                    s=mid+1;
                }
                else if(mid==n-1){
                    if(nums[mid]>=nums[mid-1]){
                        return mid;
                    }
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};