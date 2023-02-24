class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min=INT_MAX,Max=0;
        for(int i=0;i<prices.size();i++){
            Min=min(prices[i],Min);
            Max=max(Max,prices[i]-Min);
        }
        return Max;
    }
};