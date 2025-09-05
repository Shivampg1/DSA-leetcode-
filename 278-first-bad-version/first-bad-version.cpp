// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0;
        int h = n;
        while (i <= h) {
            int mid = i + (h - i) / 2;
            if (isBadVersion(mid))
                h = mid - 1;

            else {
                i = mid + 1;
            }
        }
        return i;
    }
};