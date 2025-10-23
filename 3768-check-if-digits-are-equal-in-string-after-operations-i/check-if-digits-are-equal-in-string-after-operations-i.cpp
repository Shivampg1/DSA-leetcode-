class Solution {
public:
    bool hasSameDigits(std::string s) {
        std::unordered_set<char> uniqueDigits;
        
        // Add all digits to the unordered_set
        for (int i = 0; i < s.length(); i++) {
            uniqueDigits.insert(s[i]);
        }
        
        // If there's only one unique digit, return true
        if (uniqueDigits.size() == 1) {
            return true;
        }
        
        // Reduce the digits until we have two or fewer
        while (s.length() > 2) {
            std::string newbornString;
            for (int i = 0; i < s.length() - 1; i++) {
                // Calculate new digit as the sum of adjacent digits modulo 10
                int newDigit = (s[i] - '0' + s[i + 1] - '0') % 10;
                newbornString += std::to_string(newDigit);
            }
            s = newbornString; // Update s to the new string
        }
        
        // Check if the final two digits are the same
        return s[0] == s[1];
    }
};