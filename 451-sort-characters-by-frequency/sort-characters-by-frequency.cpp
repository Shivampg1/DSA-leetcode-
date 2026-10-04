class Solution {
public:
    string frequencySort(string s) {
        string str="";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;

        for(char ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int rng=pq.top().first;
            char c=pq.top().second;

            for(int i=0;i<rng;i++){
                str+=c;
            }
             pq.pop();
        }
        return str;
    }
};