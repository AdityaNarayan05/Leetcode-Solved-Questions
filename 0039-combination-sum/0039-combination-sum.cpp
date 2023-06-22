class Solution {
public:
    vector<vector<int>> ans;
    
    void funct(int idx,int target,vector<int> &nums,vector<int> &sub){
        if(idx==nums.size()){
            if(target==0){
                ans.push_back(sub);
            }
            return;
        }
        
        if(nums[idx]<=target){
            sub.push_back(nums[idx]);
            funct(idx,target-nums[idx],nums,sub);
            sub.pop_back();
        }
        funct(idx+1,target,nums,sub);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        funct(0,target,nums,sub);
        return ans;
    }
};