class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum&1) 
            return 0;
        unordered_set<int> cur, nxt({0});
        for(int n:nums) {
            cur = nxt;
            for(int s:cur) {
                if(s==sum/2) 
                    return 1;
                if(s+n<=sum/2) 
                    nxt.insert(s+n);
            }
        }
        return 0;
    }
};