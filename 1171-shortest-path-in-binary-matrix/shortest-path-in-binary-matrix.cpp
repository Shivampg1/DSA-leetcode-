class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>src(2);
        src[0]=0;
        src[1]=0;
        vector<int>dest(2);
        dest[0]=n-1;
        dest[1]=m-1;
        if (grid[src[0]][src[1]] == 1 ||
            grid[dest[0]][dest[1]] == 1) {
            return -1;
        }
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        dist[src[0]][src[1]]=1;
        q.push({1,{src[0],src[1]}});

        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

          while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==dest[0] && c==dest[1]) return d;
              for(int i=0;i<8;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                
                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]==0 && d+1<dist[newr][newc]){
                    dist[newr][newc]=d+1;
                    
                    if(newr==dest[0] && newc==dest[1]) return dist[newr][newc];
                    
                    q.push({d+1,{newr,newc}});
                }
        
          }
          }
          return -1;
    }
};