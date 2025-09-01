#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for max heap
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max heap: {gain, pass, total}
        priority_queue<pair<double, pair<int,int>>> pq;

        for (auto &c : classes) {
            int pass = c[0], total = c[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        while (extraStudents--) {
            auto [g, pr] = pq.top(); pq.pop();
            int pass = pr.first, total = pr.second;
            pass++; total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pr] = pq.top(); pq.pop();
            sum += (double)pr.first / pr.second;
        }

        return sum / classes.size();
    }
};
