class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int res=target;
        vector<int>ans;
        int i=0;

        while(i<n){
          int need=target-numbers[i];
int idx=lower_bound(numbers.begin()+i+1, numbers.end(), need) - numbers.begin();

          if(idx<n && numbers[idx]==need){
            ans.push_back(i+1);
            ans.push_back(idx+1);
            return ans;
          }
          i++;
        }

//           if(res==0){
//             ans.push_back(i+1);
//           }
//           bool flag=binary_search(numbers.begin(), numbers.end(), res);
//           if(!flag) {
//             res=target;
//             i++;
//             //continue;
//           }
//           else{
//            int j=i;
//            ans.push_back(j+1);
//            i++;
//           }
          
//         }
//         unordered_map<int,int>mp;
//         vector<int>arr;
//         for(int num:ans){
//             mp[num]++;
//         }
//         for(auto &it:mp){
//             if(it.second>=1){
//                 arr.push_back(it.first);
//             }
//         }
//         sort(arr.begin(),arr.end());
//     vector<int>nums;
//     nums.push_back(arr[0]);
//     nums.push_back(arr[arr.size()-1]);
//     return nums;
      return ans;
     }
 };