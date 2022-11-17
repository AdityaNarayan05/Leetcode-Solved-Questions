class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr(n);
        arr[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            arr[i]=arr[i-1]+nums[i];
        
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(arr[i]);
        
        for(int i=0;i<n-1;i++)
           for(int j=i+1;j<n;j++)
                ans.push_back(arr[j]-arr[i]);
        
        sort(ans.begin(),ans.end());
        long long sum=0;
        int mod=1000000007;
        for(int i=left-1;i<=right-1;i++)
            sum+=ans[i];
        
        return sum%mod;
    }
};