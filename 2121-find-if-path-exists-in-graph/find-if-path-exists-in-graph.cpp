class Solution {
public:
    // DFS function to explore the graph
    bool dfs(int current, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        if (current == destination) return true;
        visited[current] = true;

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Track visited nodes
        vector<bool> visited(n, false);

        // Start DFS from source
        return dfs(source, destination, adj, visited);
    }
};
