class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n,0);
        vector<int> in(n,0);
        for(int i=0;i<trust.size();i++){
            out[trust[i][0]-1]++;
            in[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(out[i]==0&&in[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};