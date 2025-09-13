class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        vector<int> count;
        for(const auto & pair : freq){
            count.push_back(pair.second);
        }
        int i=0;
        int total=0;
        //int two=0;
        //int three=0;
        while(i<count.size()){
            if(count[i]==1){
                return -1;
            }
           // if(count[i] > 1){
            int two=0;
            int three=0;
                if(count[i]% 3==0){
                    three = count[i]/3;
                    
                }
                else if(count[i] % 3==1){
                    three = (count[i]/3)-1;
                    two=2;
                   
                    }
                    else{
                        three=count[i]/3;
                        two=1;
                    }
                total += two+three;
                i++;
            
            }
      return total;
            
      // return -1;
    }
};