class Solution {
public:

bool ispossible(vector<int>& nums, int threshold, int divisor){
    long long total=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        total+=ceil((double)nums[i]/divisor);
    }
    if(total<=threshold) return true;
    return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int max_val=INT_MIN;
        for(int i=0;i<n;i++){
            max_val=max(max_val,nums[i]);
        }
        int s=1;
        int e=max_val;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(nums,threshold,mid)==true){
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