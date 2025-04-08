class Solution {
public:
    vector<vector<int>> constructAdj(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto& edge : edges) {

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    // Helper function to perform DFS and find articulation points
    // using Tarjan's algorithm.
    void findPoints(vector<vector<int>>& adj, int u, vector<int>& visited,
                    vector<int>& disc, vector<int>& low, int& time, int parent,
                    vector<int>& isAP) {

        // Mark vertex u as visited and assign discovery
        // time and low value
        visited[u] = 1;
        disc[u] = low[u] = ++time;
        int children = 0;

        // Process all adjacent vertices of u
        for (int v : adj[u]) {

            // If v is not visited, then recursively visit it
            if (!visited[v]) {
                children++;
                findPoints(adj, v, visited, disc, low, time, u, isAP);

                // Check if the subtree rooted at v has a
                // connection to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // If u is not a root and low[v] is greater than or equal to
                // disc[u], then u is an articulation point
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = 1;
                }
            }

            // Update low value of u for back edge
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is root of DFS tree and has more than
        // one child, it is an articulation point
        if (parent == -1 && children > 1) {
            isAP[u] = 1;
        }
    }

    // Main function to find articulation points in the graph
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj = constructAdj(V, edges);
        vector<int> disc(V, 0), low(V, 0), visited(V, 0), isAP(V, 0);
        int time = 0;

        // Run DFS from each vertex if not
        // already visited (to handle disconnected graphs)
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                findPoints(adj, u, visited, disc, low, time, -1, isAP);
            }
        }

        // Collect all vertices that are articulation points
        vector<int> result;
        for (int u = 0; u < V; u++) {
            if (isAP[u]) {
                result.push_back(u);
            }
        }

        // If no articulation points are found, return vector containing -1
        return result.empty() ? vector<int>{-1} : result;
    }
};
