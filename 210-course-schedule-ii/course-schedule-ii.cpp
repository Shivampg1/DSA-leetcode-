class Solution {
public:

  bool iscycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges){

    vis[src]=true;
    recPath[src]=true;

    for(int i=0;i<edges.size();i++){
        int v=edges[i][0];
        int u=edges[i][1];

        if(u==src){
            if(!vis[v]){
                if(iscycle(v,vis,recPath, edges)){
                    return true;
                }
            }
            else if(recPath[v]){ //back edge -> cyclic
                    return true;
                }
        }

    }
    recPath[src]=false;
    return false;

  }


void topologic(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& edges){
     vis[src]=true;

     for(int i=0;i<edges.size();i++){
        int v=edges[i][0];
        int u=edges[i][1];

        if(u==src){
            if(!vis[v]){
                topologic(v,vis,s, edges);
                }
            }
        }
        s.push(src);

    }


    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recPath,edges)){
                    return ans;
                }
            }
        }

        stack<int>s;
        vis.assign(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                topologic(i,vis,s, edges);
                }
        }
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};