class Solution {
public:

bool ispossible(int mid,vector<int>& weights,int days){
    int n=weights.size();
    int curr=0;
    int d=1;
    for(int i=0;i<n;i++){
       if(curr+weights[i]<=mid){
        curr+=weights[i];
       }
       else{
        d++;
        curr=weights[i];
       }
    }
    if(d<=days)return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int mx=0;
        int sum=0;
        for(int i=0;i<n;i++){
            mx=max(mx,weights[i]);
            sum+=weights[i];
        }
        int s=mx;
        int e=sum;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(mid,weights,days)){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};