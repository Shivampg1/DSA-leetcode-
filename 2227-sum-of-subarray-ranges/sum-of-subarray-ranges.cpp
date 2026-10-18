class Solution {
public:

vector<int>nse(vector<int>& nums){
    int n=nums.size();
    stack<int>st;
    vector<int>l(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
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
vector<int>pse(vector<int>& nums){
    int n=nums.size();
    stack<int>st;
    vector<int>f(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
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
    long long sumMins(vector<int>& nums) {
        int n=nums.size();
        vector<int>next=nse(nums);
        vector<int>prev=pse(nums);

        long long sum=0;
        for(int i=0;i<n;i++){
        long long left=i-prev[i];
        long long right=next[i]-i;

        sum+=left*right*1ll*nums[i];
        }
        return sum;
    }
    vector<int>nge(vector<int>& nums){
    int n=nums.size();
    stack<int>st;
    vector<int>ng(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]){
            st.pop();
        }
        if(st.empty()){
            ng[i]=n;
            st.push(i);
        }
        else{
            ng[i]=st.top();
            st.push(i);
        }
    }
    return ng;
}
vector<int>pge(vector<int>& nums){
    int n=nums.size();
    stack<int>st;
    vector<int>pg(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        if(st.empty()){
            pg[i]=-1;
            st.push(i);
        }
        else{
            pg[i]=st.top();
            st.push(i);
        }
    }
    return pg;
}
    long long sumMaxi(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextg=nge(nums);
        vector<int>prevg=pge(nums);

        long long total=0;
        for(int i=0;i<n;i++){
        long long left=i-prevg[i];
        long long right=nextg[i]-i;

        total+=left*right*1ll*nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long largest=sumMaxi(nums);
        long long smallest=sumMins(nums);

        return largest-smallest;
    }
};