class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min=INT_MAX,maxPro=0;
        for(int i=0;i<prices.size();i++){
            Min=min(prices[i],Min);
            maxPro=max(maxPro,prices[i]-Min);
        }
        return maxPro;
    }
};