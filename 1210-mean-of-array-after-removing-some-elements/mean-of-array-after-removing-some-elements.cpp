class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
     
        int n=arr.size();
           int trim=n*0.05;
        int i=trim;

        long long sum=0;
        int count=0;
        while(i<n-trim){
            sum += arr[i];
            count=count+1;
            i++;
        }
        return static_cast<double>(sum)/count;
    }
};