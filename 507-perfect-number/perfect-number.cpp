class Solution {
public:
    bool checkPerfectNumber(int num) {
       vector<int> ans;
       
       for(int i=1;i<num;i++){
        if(num%i == 0){
            ans.push_back(i);
        }

       }
       int j=0;
       int sum=0;
       while(j<ans.size())
      {
         sum += ans[j];
          j++;
      }  
        if(sum==num){
            return true;
        }
       return false;
    }
};