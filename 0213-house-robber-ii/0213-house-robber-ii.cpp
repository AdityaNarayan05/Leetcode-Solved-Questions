class Solution {
public:
    int funct(vector<int> &nums){
        int n=nums.size();
        int a=nums[0];
        int b=0;
        
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=b;
            }
            int notP=0+a;
            int c=max(pick,notP);
            b=a;
            a=c;
        }
        return a;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> nums1,nums2;
        
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                nums1.push_back(nums[i]);
            if(i!=nums.size()-1)
                nums2.push_back(nums[i]);
        }
        
        int f=funct(nums1);
        int l=funct(nums2);
        
        return max(f,l);
    }
};