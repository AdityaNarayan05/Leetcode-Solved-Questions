class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& w) {
        for(auto num:w){
            if(nums.empty())
                nums.push_back(num);
            else
                nums.push_back(num+nums.back());
        }
    }
    
    int pickIndex() {
        int x=nums.back();
        int idx=rand()%x;
        auto it=upper_bound(nums.begin(),nums.end(),idx);
        return it-nums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */