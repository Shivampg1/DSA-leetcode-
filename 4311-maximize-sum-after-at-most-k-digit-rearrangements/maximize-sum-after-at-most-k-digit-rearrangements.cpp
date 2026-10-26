class Solution {
public:
    int rearrange(int num) {
        vector<int> res;

        while (num > 0) {
            int digit=num % 10;
            res.push_back(digit);
            num /= 10;
        }

        sort(res.rbegin(), res.rend());

        int result = 0;
        for (int n : res) {
            result = result * 10 + n;
        }

        return result;
    }
    long long maximizeSum(vector<int>& nums, int k) {
         long long sum = 0;
        vector<int> ans;

        for (int num : nums) {
            sum += num;
            ans.push_back(rearrange(num) - num);
        }

        sort(ans.rbegin(), ans.rend());

        for (int i = 0; i < k && ans[i] > 0; i++) {
            sum += ans[i];
        }

        return sum;
    }
};