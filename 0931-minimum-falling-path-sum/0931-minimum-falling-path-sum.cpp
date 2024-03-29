class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0), cur(n,0);
        // Initializing first row - base condition
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0;j<n;j++){

                int up = matrix[i][j] + prev[j];

                int leftDiagonal= matrix[i][j];
                if(j-1>=0) leftDiagonal += prev[j-1];
                else leftDiagonal += 1e9;

                int rightDiagonal = matrix[i][j];
                if(j+1<n) rightDiagonal += prev[j+1];
                else rightDiagonal += 1e9;

                cur[j] = min(up, min(leftDiagonal,rightDiagonal));

            }
            prev = cur;
        }

        int mini = INT_MAX;
        for(int j=0; j<n;j++){
            mini = min(mini,prev[j]);
        }

        return mini;
    }
};