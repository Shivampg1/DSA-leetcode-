// 3rd version of counting sort
const int Mx=2e6+1;
bitset<Mx> hasX=0;
vector<int> ans[100000];
class Solution {
public:
    static vector<vector<int>> minimumAbsDifference(vector<int>& arr){
        const int n=arr.size();
        int* a=arr.data(); //get C-array
        auto [m, M]=minmax_element(a, a+n);
        int bias=*m, range=*M-bias+1;
        hasX=0;// distinct integers arr
        for(int i=0; i<n; i++){
            hasX[a[i]-bias]=1;
        }
        int  minD=1e9, prevX=-1e9, j=0;

        // this part can be simplified in a single loop
        for(int i=0, idx=0; i<range; i++){
            if(!hasX[i]) continue;
            const int x=i+bias;
            a[idx++]=x;
            int curD=x-prevX;
            if (curD<minD){
                j=0;
                minD=curD;
                ans[j++]={prevX, x};
            }
            else if (curD==minD){
                ans[j++]={prevX, x};
            }
            prevX=x;
        }
        return vector<vector<int>>(ans, ans+j);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();