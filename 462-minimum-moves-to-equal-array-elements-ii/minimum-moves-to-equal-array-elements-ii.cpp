class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2];
        int med=0;
        for(int num : nums){
            med += abs(median-num); 
        }
        return med;
    }
};