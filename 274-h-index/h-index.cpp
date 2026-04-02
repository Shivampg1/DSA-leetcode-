class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int i=1;
    vector<int>ans;
        while(i<=n){
            int count=0;
            for(int j=0;j<n;j++){
                if(i<=citations[j]){
                    count++;
                }
                
            }
            ans.push_back(count);
                i++;
        }
        int res=0;
        for(int j=0;j<ans.size();j++){
            if(j<ans[j]){
                res++;
            }
        }
        return res;
        
    }
};