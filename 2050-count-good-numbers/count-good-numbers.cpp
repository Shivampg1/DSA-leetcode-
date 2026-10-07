class Solution {
public:
long long MOD=1e9+7;
long long pow(long long x,long long n){
    if(n==0) return 1;
    if(x==0) return 0;
      long long binfm=n;
      long long ans=1;
      while(binfm>0){
        if(binfm%2==1){
         ans=(ans*x)%MOD;
        }
        x=(1LL*x*x)%MOD;
        binfm/=2;
      }
      return ans%MOD;
    
}
    int countGoodNumbers(long long n) {
        //long long MOD=1e9+7;
        long long even=(n+1)/2;
        long long odd=n/2;
        
        long long res=(1LL*pow(5,even)*pow(4,odd))%MOD;

        return res;
    }
};