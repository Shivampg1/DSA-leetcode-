class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num : arr){
            freq[num]++;
        }
        int res=-1;
        for(auto& pairs : freq){
            if(pairs.second==pairs.first){
                 res=max(pairs.first,res);
            }
        }
        return res;
    }
};