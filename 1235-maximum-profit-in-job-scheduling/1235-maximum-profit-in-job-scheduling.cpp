class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int dp[50002];
        int n = startTime.size();
        vector<vector<int>> arr;
        for(int i = 0 ; i < startTime.size() ; i++)
            arr.push_back({startTime[i] , endTime[i] , profit[i]});
        
        sort(arr.begin() , arr.end());
        dp[n] = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            int idx = i+1;
            while(idx < n && arr[idx][0] < arr[i][1])
                idx++;
    
            dp[i] = max(arr[i][2] + dp[idx] , dp[i+1]);   
        }
        return dp[0];
    }
};