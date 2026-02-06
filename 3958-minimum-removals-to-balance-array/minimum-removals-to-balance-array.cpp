class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int i, l, h, mid, n = nums.size(), ans = n;
        long long int find;
        sort(nums.begin(), nums.end());

        for(i = 0; i<n; i++){

            find = (long long int )nums[i] * (long long int)k;
            l = i;
            h = n;
            
            while(l + 1 < h){
                mid = l + ((h-l)>>1);
                if(nums[mid]<=find){
                    l = mid;
                }
                else{
                    h = mid;
                }
            }

            if(l != n && nums[l] <= find){
                ans = min(ans, i+n-l-1);
            }
        }

        return ans;
    }
};