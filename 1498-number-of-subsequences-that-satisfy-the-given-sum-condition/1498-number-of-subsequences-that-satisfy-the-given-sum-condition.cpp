class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int mod = 1e9+7;
        
        int i = 0;
        int j = nums.size()-1;
        
        vector<int> pow;
        pow.push_back(1);
        for(int i = 1; i < nums.size(); i++) {
            pow.push_back((pow.back() * 2)%mod);
        }
        
        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                ans = (ans % mod + pow[j-i] % mod) % mod;
                i++;
            }
            else j--;
        }
        return ans;
    }
};