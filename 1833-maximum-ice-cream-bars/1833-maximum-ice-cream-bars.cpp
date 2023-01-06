class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int bar = 0, n = costs.size();
        sort(costs.begin(),costs.end());
        if(coins < costs[0])
            return 0;
        for(int i = 0; i < n; i++){
            if(coins <= 0 || coins < costs[i])
                break;
            coins -= costs[i];
            bar++;
        }
        return bar;
    }
};