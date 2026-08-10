class Solution {
public:

bool iscycle(int src,vector<int>& rec, vector<int>&vis,vector<vector<int>>& adj){
    vis[src]=1;
    rec[src]=1;

    for(int neigh:adj[src]){
        if(!vis[neigh]){
           if(iscycle(neigh,rec,vis,adj)) return true;
        }
        else if(rec[neigh]) return true;
    }
    rec[src]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //int V;
        vector<int>vis(numCourses,0);
        vector<int>rec(numCourses,0);
vector<vector<int>> adj(numCourses);
for(auto& p:prerequisites){
    int v=p[0];
    int u=p[1];

    adj[v].push_back(u);
}

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,rec,vis,adj)) return false;
            }
        }
        return true;
    }
};