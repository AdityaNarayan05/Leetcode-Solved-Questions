class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int num = matrix[i][j];
                if(visited[i][j] == 0){
                    visited[i][j] = 1;
                    int x = i, y = j;
                    while(x+1 < m && y+1 < n){
                        x++;y++;
                        if(visited[x][y] == 0){
                            visited[x][y] = 1;
                            if(matrix[x][y] != num){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};