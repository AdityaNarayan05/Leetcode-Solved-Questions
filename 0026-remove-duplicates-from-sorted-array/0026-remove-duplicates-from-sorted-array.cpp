class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low=1,index=1,c=1;
        while(low<nums.size()){
            if(nums[low]==nums[low-1])
                low++;
            else{   
                c++;
                nums[index]=nums[low];
                index++;
                low++;
            }
        }
        return c;
    }
};