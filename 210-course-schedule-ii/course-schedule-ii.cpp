class Solution {
public:
bool topo(int src,vector<int>&vis,vector<int>&rec,vector<vector<int>>&adj,stack<int>&st){
    vis[src]=1;
    rec[src]=1;
    for(int neigh:adj[src]){
        if(!vis[neigh]){
            if(topo(neigh,vis,rec,adj,st)) return true;
        }
        else if(rec[neigh]){
            return true;
        }
        // rec[src]=0;
    }
    rec[src]=0;
    st.push(src);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &p:prerequisites){
            int v=p[0];
            int u=p[1];
         adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>rec(numCourses,0);
        stack<int>st;
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(topo(i,vis,rec,adj,st)) return ans;
            }
        }
        while(!st.empty()){
         ans.push_back(st.top());
         st.pop();

        }
        return ans;
    }
};