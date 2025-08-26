class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        int i=0;
        int j=0;
        while(i<target.size() && j<arr.size()){
            if(target[i]==arr[j]){
                i++;
                j++;
            }
            else{
                return false;
           }
        }
        return true;
    }
};