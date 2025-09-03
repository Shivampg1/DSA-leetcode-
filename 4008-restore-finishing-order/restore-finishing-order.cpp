class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        int n=friends.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(friends[i]);
        }
        int i=0;
        while(i<order.size()){
               if(s.find(order[i]) != s.end()){
                ans.push_back(order[i]);

               }
               i++;
            }
       return ans;
    }
};