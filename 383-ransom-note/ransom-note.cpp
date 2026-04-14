class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int r=ransomNote.size();
        int m=magazine.size();
        int i=0;
        int j=0;
        int count=0;
        while(i<r && j<m){
            if(ransomNote[i]!=magazine[j]){
                j++;
            }
            else{
                count++;
                i++;
                j++;
            }
        }
        if(count==r) return true;

        return false;

    }
};