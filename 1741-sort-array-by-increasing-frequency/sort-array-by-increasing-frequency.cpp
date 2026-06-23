class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto &it:mp){
            pq.push({-it.second,it.first});

        }
        vector<int>ans;
        while(pq.size()>0){
            int s=-pq.top().first;
            int e=pq.top().second;

            for(int i=0;i<s;i++){
                ans.push_back(e);
            }
            pq.pop();
        }
        return ans;
    }
};