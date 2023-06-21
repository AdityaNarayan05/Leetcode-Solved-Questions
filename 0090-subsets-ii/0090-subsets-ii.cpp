class Solution {
public:
    vector<vector<int>> subs;
    vector<int> sub;
    
    void fun(vector<int>& nums,int x) {
        subs.push_back(sub);
        for(int i = x; i < nums.size(); i++) {
            if(i != x and nums[i] == nums[i-1]) 
                continue;
            
            sub.push_back(nums[i]);
            fun(nums,i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        fun(nums, 0);
        return subs;
    }
};