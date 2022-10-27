class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int x, int y) {
        int n = img1.size();
        int res = 0, startX = 0, startY = 0, stopX = n - abs(x), stopY = n - abs(y);
        if (x < 0) {
            startX = abs(x);
            stopX = n;
        } 
        if (y < 0) {
            startY = abs(y);
            stopY = n;
        }
        for (int i = startX; i < stopX; ++ i) {
            for (int j = startY; j < stopY; ++ j) 
                res += (img1[i + x][j + y] + img2[i][j] == 2);
        }
        return res;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0, n = img1.size();
        for (int x = 1 - n; x < n; ++ x)
            for (int y = 1 - n; y < n; ++ y)
                res = max(res, overlap(img1, img2, x, y));
        return res;
    }
};