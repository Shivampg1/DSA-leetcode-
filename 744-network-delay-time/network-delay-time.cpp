class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : times) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int src = k - 1;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if(d > dist[node])
                continue;

            for(auto ne : adj[node]) {

                int adjnode = ne.first;
                int cost = ne.second;

                if(d + cost < dist[adjnode]) {

                    dist[adjnode] = d + cost;

                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};