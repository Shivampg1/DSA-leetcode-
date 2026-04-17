class Solution {
public:

int max_val=-1;

void dfs(int src,vector<int>&vis,vector<int>&rec,vector<vector<int>>&adj,vector<int>& parent){
    vis[src]=1;
    rec[src]=1;

    for(int neigh:adj[src]){
        if(!vis[neigh]){
            parent[neigh]=src;
            dfs(neigh,vis,rec,adj,parent);
        }
        else if(rec[neigh]){
            int curr=src;
            int cyclecount=1;
              
            while(curr!=neigh){
                curr=parent[curr];
                cyclecount++;
            }
            max_val=max(max_val,cyclecount);
        }
    }
    rec[src]=0;
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> vis(n, 0), rec(n, 0), parent(n, -1);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, rec, adj, parent);
            }
        }
// if(!found){
//     return -1;
// }
        return max_val;

    }
};