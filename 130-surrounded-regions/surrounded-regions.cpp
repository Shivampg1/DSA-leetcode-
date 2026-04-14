class Solution {
public:
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>&vis,vector<vector<char>>& board){

        if(i<0||j<0||i>=n||j>=m||vis[i][j]||board[i][j]!='O') return;

        vis[i][j]=1;

        dfs(i+1,j,n,m,vis,board);
        dfs(i-1,j,n,m,vis,board);
        dfs(i,j+1,n,m,vis,board);
        dfs(i,j-1,n,m,vis,board);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,n,m,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,n,m,vis,board);
            }
         }
             for(int j=0;j<m;j++){
                if(!vis[0][j] && board[0][j]=='O'){
                    dfs(0,j,n,m,vis,board);
                }
                if(!vis[n-1][j] && board[n-1][j]=='O'){
                    dfs(n-1,j,n,m,vis,board);
                }
             }
             for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && board[i][j]=='O'){
                       board[i][j]='X';
                    }
                }
             }
             //return board;

    }
};