class Solution {
public:
    double myPow(double x, int n) {
        long long binfm=n;
        if(n==0) return 1.0;
        if(x==0) return 0.0;
      bool negative=false;

        if(n<0){
            negative = true;
            binfm=-binfm;
        }
        double ans=1.0;
        while(binfm>0){
            if(binfm%2==1){
                ans*=x;
            }
            x*=x;
            binfm/=2;
        }
        if(negative){
        return 1.0/ans;
        }
        return ans;
        
    }
};