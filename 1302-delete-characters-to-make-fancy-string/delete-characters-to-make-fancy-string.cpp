class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        
        string result;
        char prev = s[0];
        int count = 1;
        result += prev;
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == prev) {
                count++;
                if (count < 3) {
                    result += s[i];
                }
            } else {
                prev = s[i];
                count = 1;
                result += s[i];
            }
        }
        return result;
    
    }
};