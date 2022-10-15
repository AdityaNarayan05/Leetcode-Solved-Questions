class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return maxSq(matrix);
    }
    int maxSq(vector<vector<char>> &matrix){
        if (matrix.empty()) return 0;
        
        int res = 0;
        vector<vector<int>> tab(matrix.size(), vector<int>(matrix[0].size()));

        for(int row = tab.size() - 1; row >= 0; --row) {
            for(int col = tab[0].size() - 1; col >= 0; --col) {
                if (col == matrix[0].size() - 1) {
                    tab[row][col] = matrix[row][col] == '0' ? 0 : 1;
                } else if (row == matrix.size() - 1) {
                    tab[row][col] = matrix[row][col] == '0' ? 0 : 1;
                } else if (matrix[row][col] == '0') {
                    tab[row][col] = 0;
                } else {
                    tab[row][col] = min(min(tab[row+1][col], tab[row][col+1]),
                                        tab[row+1][col+1]) + 1;
                }
                res = max(res, tab[row][col]);
            }
        }
        
        return res * res;
    }
};