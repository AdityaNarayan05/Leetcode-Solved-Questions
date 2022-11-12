class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0, R = size(nums) / 2, mid;
        while(L < R){
            mid = (L + R) >> 1;
            if(nums[2*mid] == nums[2*mid + 1])
                L = mid + 1;
            else
                R = mid;
        }
        return nums[2 * R];
    }
};