class Solution {
public:

bool ispossible(vector<int>& piles, int h, int banana){
    long long total=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        total+=ceil((double)piles[i]/banana);
    }
    if(total<=h) return true;
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int max_val=INT_MIN;
        for(int i=0;i<n;i++){
            max_val=max(max_val,piles[i]);
        }
        int s=1;
        int e=max_val;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(piles,h,mid)==true){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};