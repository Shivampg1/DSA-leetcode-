class Solution {
public:
vector<int>nse(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>e(n);
    for(int i=n-1;i>=0;i--){
       while(!st.empty() && arr[i]<=arr[st.top()]){
        st.pop();
       }
       if(st.empty()){
        e[i]=n;
        st.push(i);
       }
       else{
        e[i]=st.top();
        st.push(i);
       }
    }
    return e;
}
vector<int>pse(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>f(n);
    for(int i=0;i<n;i++){
       while(!st.empty() && arr[i]<arr[st.top()]){
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
    int sumSubarrayMins(vector<int>& arr) {
        long long MOD=1e9+7;
        int n=arr.size();
        vector<int>next=nse(arr);
        vector<int>prev=pse(arr);

        long long sum=0;
        for(int i=0;i<n;i++){
        long long left=i-prev[i];
        long long right=next[i]-i;

        sum=(sum+(left*right*1ll*arr[i])%MOD)%MOD;
        }
        return sum;
    }
};