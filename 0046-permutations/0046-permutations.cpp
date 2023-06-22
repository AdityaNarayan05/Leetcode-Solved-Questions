class Solution {
public:
    vector<vector<int>> ans;
    void funct(int idx,vector<int> &nums){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            funct(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        funct(0,nums);
        return ans;
    }
};