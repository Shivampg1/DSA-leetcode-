class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
            }
            for(auto& pair : freq){
                int num=pair.first;
                int count=pair.second;
                if(count > n/3){
                    result.push_back(num);
                }
            }
        return result;
    }
};