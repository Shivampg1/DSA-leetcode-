class Solution {
public:
 bool ispossible(int mid,vector<int>& arr, int m, int k){
      int n=arr.size();
      int count=0;
      int b=0;
      for(int i=0;i<n;i++){
          if(arr[i]<=mid){
              count++;
              if(count>=k){
                  b+=count/k;
                  count=0;
              }
          }
          else{
              count=0;
          }
      }
      if(b>=m) return true;
      return false;
  }
    int minDays(vector<int>& arr, int m, int k) {
         int n=arr.size();
         if(1ll*n<1ll*m*k) return -1;
         int max_val=0;
         for(int i=0;i<n;i++){
             max_val=max(max_val,arr[i]);
         }
         int s=1;
         int e=max_val;
         int res=0;
         while(s<=e){
             int mid=s+(e-s)/2;
             
             if(ispossible(mid,arr,m,k)){
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