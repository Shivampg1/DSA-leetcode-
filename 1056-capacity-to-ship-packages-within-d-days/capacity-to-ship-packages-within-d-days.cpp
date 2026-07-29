class Solution {
public:
  
  bool ispossible(vector<int>& weights,int days, int capacity){
      int n=weights.size();
      int time=1;
      int load=0;
      for(int i=0;i<n;i++){
          if(load+weights[i]<=capacity){
              load+=weights[i];
          }
          else{
              time++;
              load=weights[i];
          }
      }
      
      if(time<=days) return true;
          return false;
  }
    int shipWithinDays(vector<int>& weights, int days) {
       int n=weights.size();
        int maxsum=0;
        int max_val=INT_MIN;

        for(int i=0;i<n;i++){
            maxsum+=weights[i];
            max_val=max(max_val,weights[i]);
        }
        int s=max_val;
        int e=maxsum;
        
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(ispossible(weights,days,mid)==true){
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