class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            for(int i=1;i<matrix.size();i++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        grid = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int double_sum = 0;
        int sum1 = 0;
        int sum2 = 0;
        if(col1>0)
            sum1 = grid[row2][col1-1];
        if(row1>0)
            sum2 = grid[row1-1][col2];
        if(row1>0 && col1>0)
            double_sum = grid[row1-1][col1-1];
        return grid[row2][col2] - sum1 - sum2 + double_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */