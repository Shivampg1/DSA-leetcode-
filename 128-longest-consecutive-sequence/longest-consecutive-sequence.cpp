class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0 ;
        sort(nums.begin(),nums.end()) ;
        vector<int> ans ;
        ans.push_back(nums[0]) ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[i-1]){
                ans.push_back(nums[i]) ;
            }
        }
        int c = 1 ;
        int maxi = 1 ;
       
        for(int i = 1 ; i< ans.size() ; i++ ){

            if( (ans[i] ) == ans[i-1] +1 ){
                c++ ;
            }
            else{
                c = 1 ;
            }
            maxi = max(c,maxi) ;

        }
        return maxi ;
    }
};