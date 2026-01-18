class Solution {
public:

void dfs(int src, vector<bool> & vis,vector<vector<int>>& isConnected){
    vis[src]=true;

    for(int i=0;i<isConnected.size();i++){
        if(isConnected[src][i] == 1 && !vis[i]){
            dfs(i,vis,isConnected);
        }
    }
}

  
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<bool> vis(V,false);
       int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
            count++;
            dfs(i,vis,isConnected);
            }
        }
        return count;
        
    }
};