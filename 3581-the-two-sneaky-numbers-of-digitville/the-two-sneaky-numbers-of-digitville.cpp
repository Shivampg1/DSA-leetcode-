class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int num :nums){
            freq[num]++;
        }
        for(auto& pair:freq){
            if(pair.second == 2){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};