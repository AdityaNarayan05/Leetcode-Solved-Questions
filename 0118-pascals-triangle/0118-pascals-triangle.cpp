class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int rowSize=0 ; rowSize<numRows ; rowSize++){
            vector<int>v(rowSize+1);
            v[0]=v[v.size()-1]=1;

            for(int i=1;i<v.size()-1;i++){
                long dig=(((long)v[i-1])*(rowSize-i+1))/i;
                v[i]=(int)(dig);
            }
            ans.push_back(v);
        }
        return ans;
    }
};