class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int count=0;


       for (int i = 0; i < n; i++) {           
        int j = i + 1;
        int k = j + 1;

        while (j < n) {
            k = j + 1;
            while (k < n) {
               if(nums[i]+nums[j]>nums[k]){
                 count++;
               }
                k++;
            }
            j++;
        }
    }
    return count;
    }
};