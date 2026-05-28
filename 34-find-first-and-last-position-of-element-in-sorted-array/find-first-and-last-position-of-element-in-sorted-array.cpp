class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        vector<int>res(2,-1);
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                res[0]=mid;
                e=mid-1;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        s = 0;
        e = nums.size() - 1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(target==nums[mid]){
                res[1]=mid;
                s=mid+1;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};