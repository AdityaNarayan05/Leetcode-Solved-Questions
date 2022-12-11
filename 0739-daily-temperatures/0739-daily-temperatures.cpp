class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        int maxTemp = 0;
        for(int currDay=n-1;currDay>=0;currDay--){
            int currTemp = temp[currDay];
            if(currTemp>=maxTemp){
                maxTemp=currTemp;
                continue;
            }
            int days = 1;
            while(currTemp>=temp[currDay+days])
                days+=ans[currDay+days];
            ans[currDay]=days;
        }
        return ans;
    }
};