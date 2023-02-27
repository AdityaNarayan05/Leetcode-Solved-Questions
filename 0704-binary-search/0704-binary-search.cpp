class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<=0)
            return -1;
        // if(nums[0]>target or nums[nums.size()-1]<target)
        //     return -1;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]<target)
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};