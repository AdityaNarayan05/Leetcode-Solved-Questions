class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int dy=c[1][1]-c[0][1];
        int dx=c[1][0]-c[0][0];
        
        for(int i=2;i<c.size();i++){
            auto p=c[i];
            if(dy*(p[0]-c[0][0])!=dx*(p[1]-c[0][1]))
                return false;
        }
        return true;
    }
};