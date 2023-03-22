class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> vis;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int preval){
        if (x < 0 or x >= matrix.size() or y < 0 or y >= matrix[0].size() or matrix[x][y] < pre) 
            return;
        if((vis[x][y] & preval) == preval)
            return;
        
        vis[x][y] |= preval;
        if (vis[x][y] == 3) 
            res.push_back({x, y});
        
        for(int i=0;i<4;i++)
            dfs(matrix, x + dir[i][0], y+dir[i][1], matrix[x][y], vis[x][y]); 
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return res;
        
        int m = matrix.size(), n = matrix[0].size();
        vis.resize(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n - 1, INT_MIN, 2);
        }
        for (int i = 0; i < n; i++) {
            dfs(matrix, 0, i, INT_MIN, 1);
            dfs(matrix, m - 1, i, INT_MIN, 2);
        }
        
        return res;
    }
};