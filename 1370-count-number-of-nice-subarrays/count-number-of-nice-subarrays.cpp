class Solution {
public:

int atMost(vector<int>& nums, int k) {
        int n=nums.size();
        if (k < 0) return 0;
        int i=0;
        int j=0;
        int sum=0;
        int count=0;
        while(j<n){
         sum+=(nums[j]%2);
           while (sum > k) {
                sum -= (nums[i]%2);
                i++;
            }

            count += j - i + 1;
            j++;

        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atMost(nums, k) - atMost(nums, k- 1);
    }
};