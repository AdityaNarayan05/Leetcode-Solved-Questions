class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& nums, vector<int>& v, int x) {
        ans.push_back(v);
        for(int i = x; i < size(nums); i++) {
            if(i != x and nums[i] == nums[i-1]) 
                continue;
            
            v.push_back(nums[i]);
            fun(nums, v, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> v;
        fun(nums, v, 0);
        return ans;
    }
};