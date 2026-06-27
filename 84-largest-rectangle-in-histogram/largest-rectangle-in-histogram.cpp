class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>r;
        vector<int>l;
        stack<pair<int,int>>s;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                r.push_back(n);
            }
            else if(s.size()>0 && s.top().first<heights[i]){
                r.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    r.push_back(n);
                }
                else{
                    r.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(r.begin(),r.end());
        
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                l.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                l.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.size()==0){
                    l.push_back(-1);
                }
                else{
                    l.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        vector<int>w;
        for(int i=0;i<n;i++){
            int j=r[i]-l[i]-1;
            w.push_back(j);
        }
        vector<int>area;
        for(int i=0;i<n;i++){
            int k=heights[i]*w[i];
            area.push_back(k);
        }
        
        int max_val=INT_MIN;
        for(int i=0;i<area.size();i++){
            max_val=max(max_val,area[i]);
        }
        return max_val;
    }
};