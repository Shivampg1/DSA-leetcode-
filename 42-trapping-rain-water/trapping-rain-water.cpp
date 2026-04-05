class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // int leftmax=height[0];
        // int rightmax=height[n-1];
        // int i=1;
        // int j=n-2;
        // while(i<j){
        //     if(leftmax<height[i+1]){
        //         leftmax=height[i+1];
        //         i++;
        //     }
        //     if(rightmax<height[j-1]){
        //         rightmax=height[j-1];
        //        j--;
        //     }
        //     i++;
        //     j--;
        // }
        vector<int>left(n);
        vector<int>right(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }


        int total=0;
        for(int i=0;i<n;i++){
            total += min(left[i],right[i])-height[i];
        }
        return total;

    }
};