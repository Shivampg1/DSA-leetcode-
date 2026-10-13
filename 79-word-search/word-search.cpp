class Solution {
public:
bool solve(int k,int i,int j,int n,int m,vector<vector<char>>& board,string word,int w){
    if(k==w){
        return true;
    }
    if(i<0||j<0||i>=n||j>=m||board[i][j]!=word[k]){
        return false;
    }
        char ch=board[i][j];
        board[i][j]='#';
        bool found= solve(k+1,i+1,j,n,m,board,word,w)||
        solve(k+1,i-1,j,n,m,board,word,w)||
        solve(k+1,i,j+1,n,m,board,word,w)||
        solve(k+1,i,j-1,n,m,board,word,w);
        
        board[i][j]=ch;
    return found;
    //ans-=word[k];
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
       
        int w=word.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] &&
                    solve(0,i,j,n,m,board,word,w)){

                    return true;
                }
            }
        }
        return false;
    }
};