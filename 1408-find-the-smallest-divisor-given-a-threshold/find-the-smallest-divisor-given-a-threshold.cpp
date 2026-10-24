class Solution {
public:

bool ispossible(int mid,vector<int>& nums, int threshold){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]%mid==0){
            sum+=nums[i]/mid;
        }
        else{
            sum+=(nums[i]/mid)+1;
        }
        if(sum>threshold){
            break;
        }
    }
    if(sum<=threshold) return true;
    return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }
        int s=1;
        int e=mx;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(mid,nums,threshold)){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};