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
        
        // dp iterative approach
//         for(int i = n-1 ; i >= 0 ; i--){
//             int idx = i+1;
//             while(idx < n && arr[idx][0] < arr[i][1])
//                 idx++;
    
//             dp[i] = max(arr[i][2] + dp[idx] , dp[i+1]);   
//         }
        
        // space optmised dp
        for(int i = n-1 ; i >= 0 ; i--){
            int key = arr[i][1];
            int lo = i+1 , hi = n-1 , mid;
            while(lo < hi){
                mid = lo + (hi-lo)/2;
                if(arr[mid][0] >= key)
                    hi = mid;
                else
                    lo = mid+1;
            }
            int idx = lo;
            if(lo == n || arr[lo][0] < arr[i][1])
               idx = n;
            
            dp[i] = max(arr[i][2] + dp[idx] , dp[i+1]);
        }
        return dp[0];
    }
};