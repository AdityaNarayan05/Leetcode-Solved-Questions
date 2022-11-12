class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //we need to think greedily for the solution
        //uisng sliding window approach
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long l=0;
        long long r=0;
        long long total=0;
        long long ans=INT_MIN;
        //this is the main formula --nums[r]*size of sliding window<total till now +k
        while(r<n){
            total+=nums[r];
            while(nums[r]*(r-l+1)>total+k){
                total-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};