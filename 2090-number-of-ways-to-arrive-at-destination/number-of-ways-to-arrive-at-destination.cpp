class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int,int>>>adj(n);
        for(auto e:roads){
            int u=e[0];
            int v=e[1];
            int tm=e[2];
            adj[u].push_back({v,tm});
            adj[v].push_back({u,tm});
        }
      const int mod=1e9+7;
        
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
           vector<long long> dist(n, LLONG_MAX);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int time=it.second;
                 if (d > dist[node])
                continue;
                if(d+time<dist[adjnode]){
                    dist[adjnode]=d+time;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(d+time==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
                
            }
        }
        return (ways[n-1])%mod;
    }
};