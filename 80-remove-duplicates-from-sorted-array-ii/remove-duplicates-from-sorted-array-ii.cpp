class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        for(int i=0;i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
                count++;
                if(count>2){
                    // for(int j=i+1;j<nums.size()-1;j++){
                    //     nums[j]=nums[j+1];
                    // }
                    //nums[nums.size()-1]=-1;

                    nums.erase(nums.begin()+i+1);
                }
                else{
                i++;
                }
            }
            else{
                count=1;
                //continue;
                i++;
            }
        }
//   int res=0;
//         for(int i = 0; i < nums.size(); i++){
//         if(nums[i]!=-1){
//             res++;
//         }
//     }
      
       //return res;
       return nums.size();
    }
};