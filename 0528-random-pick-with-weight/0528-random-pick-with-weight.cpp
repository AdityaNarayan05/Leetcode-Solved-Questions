class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& w) {
        nums.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            nums.push_back(nums[i-1]+w[i]);
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