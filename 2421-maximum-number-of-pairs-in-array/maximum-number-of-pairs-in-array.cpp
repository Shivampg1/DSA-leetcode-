class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x : nums)
        m[x]++;

        int n = nums.size();
        int pair = 0;
        for(auto x : m){
            pair += x.second / 2;
            n -= (x.second / 2 ) * 2;
        }
        vector<int> ans(2,0);
        ans[0] = pair;
        ans[1] = n;
        return ans;
    }
};