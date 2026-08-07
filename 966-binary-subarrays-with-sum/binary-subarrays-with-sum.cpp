class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int n=nums.size();
         if (goal < 0) return 0;
        int i=0;
        int j=0;
        int sum=0;
        int count=0;
        while(j<n){
         sum+=nums[j];
           while (sum > goal) {
                sum -= nums[i];
                i++;
            }

            count += j - i + 1;
            j++;

        }
        return count;
    }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};