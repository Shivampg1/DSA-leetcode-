class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;

            if(r==n-1 && c==m-1) return diff;

            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int effort=max(abs(heights[r][c]-heights[newr][newc]),diff);
                    if(effort<dist[newr][newc]){
                        dist[newr][newc]=effort;
                        pq.push({effort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};