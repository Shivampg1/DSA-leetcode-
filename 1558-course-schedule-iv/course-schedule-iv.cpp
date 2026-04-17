class Solution {
public:

bool dfs(int src,int target,vector<int>& vis,vector<vector<int>>&adj){
    if(src==target) return true;

    vis[src]=1;
    for(int neigh:adj[src]){
        if(!vis[neigh]){
            if(dfs(neigh,target,vis,adj)) return true;
        }
    }
    return false;
}
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        // vector<int>vis(numCourses,0);
        for(auto & p:prerequisites){
            int u=p[0];
            int v=p[1];
            adj[u].push_back(v);
        }
        vector<bool>ans;
        for(auto &q : queries){
            vector<int>vis(numCourses,0);
            int u=q[0];
            int v=q[1];

            if(dfs(u,v,vis,adj)) ans.push_back(true);

            else{
                ans.push_back(false);
            }


        }
        return ans;
    }
};