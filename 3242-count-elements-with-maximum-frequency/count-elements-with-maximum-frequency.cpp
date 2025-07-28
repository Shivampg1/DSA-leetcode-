class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> freqMap;
        int max_freq=0;
        for(int num : nums){
            freqMap[num]++;
            max_freq=max(max_freq,freqMap[num]);
        }
        int total=0;
        for(auto pair : freqMap){
            if(pair.second==max_freq){
                total += pair.second;
            }
        }
        return total;
    }
};