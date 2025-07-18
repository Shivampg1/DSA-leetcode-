class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> seen;
        int max_length=0;
        int left=0;
        for(int right=0;right<n;right++){
            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};