class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long total = 0;
        for(auto i : nums) {
            total += i;
        }
        int min = numeric_limits<int>::max();
        long leftsum = 0;
        const int sz = nums.size();
        int ans = 0;
        for(int i = 0; i < sz; ++i) {
            leftsum += nums[i];
            int leftavg = leftsum / (i + 1);
            int rightavg = (sz - i - 1 == 0) ? 0 : (total - leftsum) / (sz - i - 1);
            if(abs(leftavg - rightavg) < min) {
                min = abs(leftavg - rightavg);
                ans = i;
            }
        }
        return ans;
    }
};