class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        unordered_map<int,int>count;

        vector<int>ans;
        for(int num:arr){
            freq[num]++;
        }
        for(const auto pairs:freq){
          ans.push_back(pairs.second);
        }

        for(int i:ans){
            count[i]++;
        }
        for(const auto p:count){
            if(p.second!=1){
                return false;
            }
            // else{
            //     return false;
            // }
        }
        return true;

    }
};