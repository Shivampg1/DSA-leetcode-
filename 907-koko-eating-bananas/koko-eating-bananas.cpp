class Solution {
public:
bool ispossible(int mid,vector<int>& piles,int h){
    int n=piles.size();
    long long hr=0;
    for(int i=0;i<n;i++){
        if(piles[i]%mid==0){
            hr+=piles[i]/mid;
        }
        else{
            hr+=(piles[i]/mid)+1;
        }
    }
    if(hr<=h){
        return true;
    }
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
        mx=max(mx,piles[i]);
        }
        int s=1;
        int e=mx;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(mid,piles,h)){
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