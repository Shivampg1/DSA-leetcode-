class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int max_mp=0;
        int max_val=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            max_mp=max(max_mp,mp[s[j]]);
            
            if((j-i+1)-max_mp<=k){
                max_val=max(max_val,j-i+1);
                j++;
            }
            else if((j-i+1)-max_mp>k){
                while((j-i+1)-max_mp>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                }
                j++;
            }
        }
        return max_val;
    }
};