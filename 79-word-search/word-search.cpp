class Solution {
public:
void solve(int k,int i,int j,int n,int m,vector<vector<char>>& board,string word,int w,string &ans, string &arr,vector<vector<int>> &vis){
    if(k==w){
        ans=arr;
        return;
    }
    if(i<0||j<0||i>=n||j>=m||vis[i][j]){
        return;
    }
    if(board[i][j]==word[k]){
        arr+=word[k];
        vis[i][j]=1;
        solve(k+1,i+1,j,n,m,board,word,w,ans,arr,vis);
        solve(k+1,i-1,j,n,m,board,word,w,ans,arr,vis);
        solve(k+1,i,j+1,n,m,board,word,w,ans,arr,vis);
        solve(k+1,i,j-1,n,m,board,word,w,ans,arr,vis);
        arr.pop_back();
        vis[i][j]=0;
    }
    //ans-=word[k];
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        string ans="";
        string arr="";
        int w=word.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    solve(0,i,j,n,m,board,word,w,ans,arr,vis);

                  if(ans==word) return true;
                }
            }
        }
        return false;
        //solve(0,0,0,n,m,board,word,w,ans)
    }
};