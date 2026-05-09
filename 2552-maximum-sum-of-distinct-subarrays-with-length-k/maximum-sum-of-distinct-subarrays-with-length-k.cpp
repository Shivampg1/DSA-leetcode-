class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
       long long max_val=0;
long long sum=0;
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(mp.size()==k){
                    max_val=max(max_val,sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return max_val;
    }
};