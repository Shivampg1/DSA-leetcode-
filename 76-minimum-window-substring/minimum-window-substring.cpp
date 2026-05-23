class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char c:t){
            mp[c]++;
        }
        int i=0;
        int j=0;
        int count=mp.size();
        int start=-1;
        int min_val=INT_MAX;
        string str;
        while(j<n){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;

            if(count!=0){
                j++;
            }
            else if(count==0){
                while(mp[s[i]]<0){
                    mp[s[i]]++;
                    i++;
                }
                if(j-i+1<min_val){
                    min_val=j-i+1;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]==1) count++;

                i++;
                j++;
            }
        }
    if(start == -1)
    return "";
    
        for(int u=start;u<start+min_val;u++){
            str.push_back(s[u]);
        }
        return str;
    }
};