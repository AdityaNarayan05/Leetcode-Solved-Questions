class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if(i - 1 >=0 && i - 1 < m && j - 1 >= 0 && j - 1 < n)
                    if (matrix[i][j] != matrix[i - 1][j - 1])
                        return false;
        return true;
    }
};