class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e9, n = dist.size();
        if(n - 1 >= hour)
            return -1;
        while(l < r){
            int m = (l + r) / 2;
            double sum = 0;
            for(int i = 0; i < n - 1; ++i){
                sum += ceil(dist[i] * 1.0 / m);
            }
            sum += dist[n - 1] * 1.0 / m;
            if(sum > hour)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};