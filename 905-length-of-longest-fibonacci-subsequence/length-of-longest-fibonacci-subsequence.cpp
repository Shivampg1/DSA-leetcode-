class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
      
       unordered_set<int> ans(arr.begin(),arr.end());
       int maxLen=0;
       for(int st=0;st<n;st++){
        for(int en=st+1;en<n;en++){
            int prev=arr[en];
            int curr=arr[st]+arr[en];
            int len=3;

         while(ans.find(curr)!=ans.end()){
            int temp=curr;
            curr += prev;
            prev=temp;
            maxLen=max(maxLen, len++);
         }

        }
       }
       return maxLen;
        
    }
};