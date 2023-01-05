class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count=1;
        int temp=points[0][1];
        for(int i=0; i<points.size()-1; i++){
            if(points[i+1][0] <= temp){
                if(points[i+1][1] > temp)
                    continue;
            }else{
                count++;
            }
            temp = points[i+1][1];
        }
        return count;
    }
};