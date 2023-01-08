class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        int res = 0;
    for(int i = 0; i < pts.size(); i++){
        int sp = 1;
        unordered_map<double, int> mp;
        for(int j = i + 1; j < pts.size(); j++){
            if(pts[i][0] == pts[j][0] && pts[i][1] == pts[j][1]){
                sp++;
            }
            else if(pts[i][0] == pts[j][0]){
                mp[INT_MAX]++;
            }
            else{
                double slope = double(pts[i][1] - pts[j][1]) / double(pts[i][0] - pts[j][0]);
                mp[slope]++;
            }
        }
        int localMax = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += sp;
        res = max(res, localMax);
    }
    return res;
    }
};