class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        for (int key : rooms[0]) {
            q.push(key);
            visited[key] = true;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();   
            for (int v : rooms[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        return true;
    }
};