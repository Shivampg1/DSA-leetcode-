class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        vector<int> ans;
        int i = 0;
        int current = 0;

        while (i < trips.size()) {
            int num = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];

            for (int j = 0; j < ans.size(); j++) {
                if (trips[j][2] <= start) {
                    current -= ans[j]; 
                    ans[j] = 0;
                }
            }

            ans.push_back(num);
            current += num;

            if (current > capacity) return false;

            i++;
        }

        return true;
    }
};
