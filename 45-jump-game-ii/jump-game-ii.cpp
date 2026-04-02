class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        int max_val = 0;
        int end = 0;
        int i = 0;
        int count = 0;

        while(i < n - 1){

            if(max_val < nums[i] + i){
                max_val = nums[i] + i;
            }

            // only jump when we reach boundary AND not last index
            if(i == end){
                count++;
                end = max_val;
            }

            i++;
        }

        return count;
    }
};