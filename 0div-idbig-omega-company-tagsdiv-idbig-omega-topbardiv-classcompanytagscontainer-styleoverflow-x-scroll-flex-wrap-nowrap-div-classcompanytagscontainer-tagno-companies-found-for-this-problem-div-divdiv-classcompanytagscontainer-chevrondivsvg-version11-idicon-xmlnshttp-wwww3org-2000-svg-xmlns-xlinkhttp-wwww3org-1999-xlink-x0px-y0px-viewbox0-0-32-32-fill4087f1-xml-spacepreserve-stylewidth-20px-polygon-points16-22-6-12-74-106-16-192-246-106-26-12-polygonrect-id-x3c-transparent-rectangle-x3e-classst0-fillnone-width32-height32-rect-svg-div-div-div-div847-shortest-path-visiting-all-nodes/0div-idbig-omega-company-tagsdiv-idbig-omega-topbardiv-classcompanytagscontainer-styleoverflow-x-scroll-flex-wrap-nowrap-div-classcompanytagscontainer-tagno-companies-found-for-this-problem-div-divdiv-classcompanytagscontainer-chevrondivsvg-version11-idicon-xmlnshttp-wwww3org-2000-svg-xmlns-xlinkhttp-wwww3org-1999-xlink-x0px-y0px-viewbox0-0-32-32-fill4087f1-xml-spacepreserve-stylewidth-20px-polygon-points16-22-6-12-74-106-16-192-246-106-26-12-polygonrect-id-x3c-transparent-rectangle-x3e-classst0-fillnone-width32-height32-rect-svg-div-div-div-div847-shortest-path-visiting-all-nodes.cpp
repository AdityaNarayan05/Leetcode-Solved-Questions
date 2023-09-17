class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0});
            dp[1 << i][i] = 0;
        }

        while (!q.empty()) {
            auto [visited, node, dist] = q.front();
            q.pop();

            if (visited == (1 << n) - 1) {
                return dist;
            }

            for (int neighbor : graph[node]) {
                int new_visited = visited | (1 << neighbor);

                if (dp[new_visited][neighbor] > dist + 1) {
                    dp[new_visited][neighbor] = dist + 1;
                    q.push({new_visited, neighbor, dist + 1});
                }
            }
        }

        return -1;
    }
};