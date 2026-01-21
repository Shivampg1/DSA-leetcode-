class Solution {
public:

bool dfs(int src, int currColor, vector<int> &color, vector<vector<int>>& graph){

    color[src]=currColor;
    for(int v : graph[src]){
        if(color[v]==-1){
            if(!dfs(v,!currColor,color,graph)){
                return false;
            }
        }
        else if(color[v]==currColor){
            return false;
        }
    }
    return true;
}


    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);

        for(int j=0;j<V;j++){
            if(color[j]==-1){
                if(!dfs(j,0,color,graph)){
                    return false;
                }
            }
            
        }
        return true;
    }
};