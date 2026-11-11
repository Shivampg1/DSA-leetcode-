class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int m) {
          int n=arr.size();
        if(n%m!=0)return false;
        
        map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        while(!mp.empty()){
            int st=mp.begin()->first;
            for(int i=0;i<m;i++){
                int curr=st+i;
                if(mp[curr]==0) return false;
                
                mp[curr]--;
                if(mp[curr]==0){
                    mp.erase(curr);
                }
            }
        }
        return true;
    }
};