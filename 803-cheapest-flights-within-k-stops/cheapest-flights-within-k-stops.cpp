class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int p=it[2];
            adj[u].push_back({v,p});
        }
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int d=it.second.second;

            for(auto ne:adj[node]){
                  int adjnode=ne.first;
                  int cost=ne.second;

                  if(d+cost<dist[adjnode] && stop<=k){
                    dist[adjnode]=d+cost;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                  }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};