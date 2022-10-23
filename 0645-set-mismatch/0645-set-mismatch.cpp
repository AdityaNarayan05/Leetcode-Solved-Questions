class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i<nums.size()){
            int correct = nums[i]-1;
            if(nums[i]!=nums[correct])
                swap(nums[i],nums[correct]);
            else
                i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1 ){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};