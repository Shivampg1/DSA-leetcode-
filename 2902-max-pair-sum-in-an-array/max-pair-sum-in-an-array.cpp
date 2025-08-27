class Solution {
public:
    vector<int>largestdigit(vector<int>& nums) {
        vector<int>maxim;
       
        for(int i=0;i<nums.size();i++){
             int maximum=-1;
            int temp=nums[i];
            while(temp>0){
                int digit=temp%10;
                maximum=max(maximum,digit);
                temp=temp/10;
            }
            maxim.push_back(maximum);
        }
        return maxim;
    }
    int maxSum(vector<int>& nums){
       vector<int>maxim=largestdigit(nums);
         int max_val=-1;
         int i=0;
         while(i<maxim.size()){
            int j=i+1;
            while(j<maxim.size()){
                if(maxim[i]==maxim[j]){
                    int sum= (nums[i]+nums[j]);
                    max_val=max(sum,max_val);
                }
                j++;
            }
            i++;
         }
         return max_val;
       
    }
};