class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>preL(n);
        vector<int>sufR(n);
        preL[0]=height[0];
        for(int i=1;i<n;i++){
            preL[i]=max(preL[i-1],height[i]);
        }
        sufR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufR[i]=max(sufR[i+1],height[i]);
        }
        vector<int>water(n);
        int total=0;
        for(int i=0;i<n;i++){
            water[i]=min(preL[i],sufR[i])-height[i];
            total+=water[i];
        }
        return total;

    }
};