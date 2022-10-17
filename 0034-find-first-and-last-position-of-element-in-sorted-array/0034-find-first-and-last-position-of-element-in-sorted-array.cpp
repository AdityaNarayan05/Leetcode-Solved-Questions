class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        bool cnt=true;
        if(nums.size()==0)
            return {first,last};
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target and cnt){
                first=i;
                cnt=false;
            }else if(nums[i]==target){
                last=i;
            }
        }
        if(first!=-1 &&last==-1)
            last=first;
        return {first,last};
    }
};