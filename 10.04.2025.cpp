class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0; // Start from the first node
        int cost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            // Find the unvisited node with the smallest minDist
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            cost += minDist[u];

            // Update minDist for unvisited neighbors
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return cost;
    }
};
