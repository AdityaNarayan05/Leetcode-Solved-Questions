class Solution {
public:
    bool check(int num, vector<int> &nums) { 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= num) 
                return (nums.size() - i) == num;                
        }
        return false;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() ; i++) { // O(N)
            if (check(i, nums)) return i; // O(N)
        }
        return -1;
    }
};