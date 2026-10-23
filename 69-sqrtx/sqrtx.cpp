class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int s=1;
        int e=x;
        int res=-1;
        
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid*mid<=x){
                res=mid;
                s=mid+1;
            }
            else{
              e=mid-1;
            }
        }
        return res;
    }
};