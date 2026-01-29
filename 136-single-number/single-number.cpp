class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int>ans;
        for(int neigh : nums){
            freq[neigh]++;
        }
        vector<pair<int,int>> v;

      for(auto it : freq) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
        for(auto p:v){
            ans.push_back(p.second);
        }
        return ans.front();
    }
};