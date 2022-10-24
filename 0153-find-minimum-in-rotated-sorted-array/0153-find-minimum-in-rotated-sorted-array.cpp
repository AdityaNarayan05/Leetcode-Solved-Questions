class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        int res = nums[mid];
        while(left <= right) {
            mid = (left + right) / 2;
            int cur = nums[mid];
            int lval = nums[left], rval = nums[right];
            if (cur >= lval && cur > rval) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            res = min(res, cur);
        }
        return res;
    }
};