class Solution {
public:

bool ispossible(vector<int>& nums, int k, int large){
    int count=1;
    int time=0;

    for(int i=0;i<nums.size();i++){
        if(time+nums[i]<=large){
            time+=nums[i];
        }
        else{
            count++;
            time=nums[i];
        }
    }
    if(count<=k) return true;
    else{
        return false;
    }
}
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int max_val=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            max_val=max(max_val,nums[i]);
        }
        int s=max_val;
        int e=sum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};