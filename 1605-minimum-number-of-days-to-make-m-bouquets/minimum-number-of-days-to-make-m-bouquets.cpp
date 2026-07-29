class Solution {
public:

bool ispossible(vector<int>& bloomDay, int m, int k, int days){
    vector<int>v;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=days){
            v.push_back(i);
        }
    }
    if(v.size()<m*k){
        return false;
    }
    //int count=1;
    int b=0;
    int count = 0;

for (int i = 0; i < v.size(); i++) {

    if (i == 0 || v[i] == v[i-1] + 1)
        count++;
    else
        count = 1;

    if (count == k) {
        b++;
        count = 0;   
    }
}
    if(b>=m) return true;
    else{
        return false;
    }

}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
          if ((long long)m * k > n)
         return -1;

        int max_val=INT_MIN;
        int min_val=INT_MAX;

        for(int i=0;i<n;i++){
            max_val=max(max_val,bloomDay[i]);
            min_val=min(min_val,bloomDay[i]);
        }
        int s=min_val;
        int e=max_val;
       int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(bloomDay,m,k,mid)==true){
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