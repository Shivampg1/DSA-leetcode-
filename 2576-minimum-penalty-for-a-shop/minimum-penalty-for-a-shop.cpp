class Solution {
public:
       int bestClosingTime(string s) {
        int pen = 0;
        for (char c : s) if (c == 'Y') pen++;

        int best = pen, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'Y') pen--;
            else pen++;

            if (pen < best) {
                best = pen;
                ans = i + 1;
            }
        }
        return ans;
    }
};