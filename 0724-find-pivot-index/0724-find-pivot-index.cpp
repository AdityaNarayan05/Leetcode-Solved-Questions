class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls=0;
        int rs=0;
        for(auto num : nums)
            rs+=num;
        rs=rs-nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ls+=0;
                rs-=0;
            }
            else{
                ls+=nums[i-1];
                rs-=nums[i];
            }
            if(ls==rs)
                return i;
        }
        return -1;
    }
};