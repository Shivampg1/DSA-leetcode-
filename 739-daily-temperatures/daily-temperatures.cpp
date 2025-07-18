class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {

            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_day = st.top();
                answer[prev_day] = i - prev_day; 
                st.pop(); 
            }
            st.push(i);
        }
        
        return answer;
    }
};