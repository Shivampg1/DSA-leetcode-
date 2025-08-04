class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;

        for (int house : houses) {
            int minDist = INT_MAX;
            for (int heater : heaters) {
                minDist = min(minDist, abs(house - heater));
            }
            radius = max(radius, minDist);
        }

        return radius;
    }
};