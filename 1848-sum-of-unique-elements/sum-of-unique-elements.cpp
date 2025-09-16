class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>freq;
        vector<int>ans;

        for(int num:nums){
            freq[num]++;
        }
        for(const auto pair:freq){
            if(pair.second==1){
                ans.push_back(pair.first);
            }
        }
        int count=0;
        for(int i=0;i<ans.size();i++){
            count += ans[i];
        }
        return count;
    }
};