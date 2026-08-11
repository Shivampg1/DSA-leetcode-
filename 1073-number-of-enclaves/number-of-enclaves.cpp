class Solution {
public:

void bfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<int>> &grid){
    queue<pair<int,int>>q;
    q.push({i,j});
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    vis[i][j]=1;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
          
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                bfs(i,0,n,m,vis,grid);
            }

        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1]==1){
                bfs(i,m-1,n,m,vis,grid);
            }
        }
            for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                bfs(0,j,n,m,vis,grid);
            }
            
        }
         for(int j=0;j<m;j++){
            if(!vis[n-1][j] && grid[n-1][j]==1){
                bfs(n-1,j,n,m,vis,grid);
            }
        }
         int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;

    }
};