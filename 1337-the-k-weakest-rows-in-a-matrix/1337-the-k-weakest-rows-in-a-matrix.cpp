class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // 1 --> soldiers , 0---> civilians
        int m = mat.size(), n = mat[0].size();
        vector<pair<int,int>> arr;
        for(int i = 0;i<m;i++){
            int low = 0, high = n-1;
            int pos1 = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(mat[i][mid] == 1){
                    if(mid+1 > n-1 || mat[i][mid+1] == 0){
                        pos1 = mid;
                        break;
                    }
                    else{
                        pos1 = mid;
                        low = mid+1;
                    }
                }
                else 
                    high = mid-1;
            }
            arr.push_back({pos1, i});
        }
        vector<int> ans;
        sort(arr.begin(),arr.end());
        int i = 1;
        for(auto it : arr){
            ans.emplace_back(it.second);
            if(i == k) break;
            i++;
        }
        return ans;
    }
};