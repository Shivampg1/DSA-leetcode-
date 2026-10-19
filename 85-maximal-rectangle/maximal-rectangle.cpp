class Solution {
public:

vector<int>nse(vector<int>& heights){
    int n=heights.size();
    stack<int>st;
    vector<int>l(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(st.empty()){
            l[i]=n;
            st.push(i);
        }
        else{
          l[i]=st.top();
          st.push(i);
        }
    }
    return l;
}
vector<int>pse(vector<int>& heights){
    int n=heights.size();
    stack<int>st;
    vector<int>f(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            st.pop();
        }
        if(st.empty()){
            f[i]=-1;
            st.push(i);
        }
        else{
          f[i]=st.top();
          st.push(i);
        }
    }
    return f;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nxt=nse(heights);
        vector<int>prv=pse(heights);
        int n=heights.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=prv[i];
            int right=nxt[i];
            
            sum=max(sum,(right-left-1)*heights[i]*1ll);
        }
        return sum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>heights(m,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(matrix[i][j]=='0') heights[j]=0;

           else{
            heights[j]++;
           }
        }
        ans=max(ans,largestRectangleArea(heights));

       }
       return ans;
        
    }
};