class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool alive=true;
            while(!st.empty() && asteroids[i]<0 && st.top() > 0){
                if(abs(asteroids[i])>st.top()){
                    st.pop();
                }
                else if(abs(asteroids[i])==st.top()){
                    st.pop();
                    alive=false;
                    break;
                }
                else{
                    alive=false;
                    break;
                }
            }
            if(alive){
                st.push(asteroids[i]);
            }

        }
         vector<int> ans(st.size());

        for (int i = (int)st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};