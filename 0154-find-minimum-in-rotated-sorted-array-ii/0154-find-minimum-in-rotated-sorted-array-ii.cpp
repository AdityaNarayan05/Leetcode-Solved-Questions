class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1])
            return nums[0];
        
        int l = 0, h = n - 1;
        while(l < h){
            int mid = l + (h-l)/2;
            if(nums[mid] > nums[h])
                l = mid + 1;
            else if(nums[h] > nums[mid])
                h = mid;
            else
                h--;
        }
        return nums[l];
    }
};