class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> div;
            for(int j=1; j<=sqrt(nums[i]); j++){
                if(nums[i] % j == 0){
                    div.push_back(j);
                    if(j!= (nums[i]) / j){
                        div.push_back(nums[i]/j);
                    }
                }
            }
            if (div.size() == 4) {
                for (int x : div) {
                    ans += x;
                }
            }
        }
        return ans;
    }
};