class Solution {
public:
    vector<pair<bool,bool>> mem;
    const vector<vector<int>>* __restrict__ pHs;
    int m;
    int n;

    void dfs(const int i, const int j, const int h, const pair<bool,bool> curr){
        if (i < 0 || j < 0) 
            return; 
        if (i >= m || j >= n) 
            return; 
        
        const int he = (*pHs)[i][j];
        if (he < h) 
            return;
        const int index = n * i + j;
        if ((mem[index].first == curr.first || mem[index].first) && (mem[index].second == curr.second || mem[index].second)) 
            return;
        mem[index].first |= curr.first;
        mem[index].second |= curr.second;

        dfs(i+1, j, he, curr);
        dfs(i-1, j, he, curr);
        dfs(i, j+1, he, curr);
        dfs(i, j-1, he, curr);
    }


    vector<vector<int>> pacificAtlantic(const vector<vector<int>>& heights) {
        m = int(heights.size());
        n = int(heights[0].size());
        mem.resize(m * n);
        pHs = &heights;

        for(int i=0;i<m;++i){
            dfs(i, 0, heights[i][0], {true, false});
            dfs(i, n-1, heights[i][n-1], {false, true});
        }

        for(int j=0;j<n;++j){
            dfs(0, j, heights[0][j], {true, false});
            dfs(m-1, j, heights[m-1][j], {false, true});
        }

        vector<vector<int>> ans;
        ans.reserve(m * n);

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                const int index = n * i + j;
                const auto[po, ao] = mem[index];
                if (po && ao){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;  
    }
};