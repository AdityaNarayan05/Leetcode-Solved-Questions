class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for (auto& row: grid)
            for (auto& i: row)
                if (i < 0)
                    ans++;
        return ans;
    }
};