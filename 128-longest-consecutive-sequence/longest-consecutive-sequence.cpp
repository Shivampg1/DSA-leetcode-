class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0) return 0;
        int max_val=1;
        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int x=it;
                int count=1;
                while(s.find(x+1)!=s.end()){
                    x=x+1;
                    count++;
                }
                 max_val=max(max_val,count);
            }
        }
        return max_val;
    }
};