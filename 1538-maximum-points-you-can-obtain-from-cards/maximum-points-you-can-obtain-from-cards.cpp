class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total=0;
        for(int i=0;i<k;i++){
            total += cardPoints[i];
        }
        int val=total;
        int right=0;
         for(int j=0;j<k;j++){
            right += cardPoints[n-1-j];
            total -= cardPoints[k-1-j];
            val=max(val,total+right);
        }
        return val;


    }
};