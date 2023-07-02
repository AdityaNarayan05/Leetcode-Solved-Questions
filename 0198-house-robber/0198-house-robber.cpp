class Solution {
public:
    int funct(int n,vector<int> &nums){
        // if(n==0)
        //     return nums[0];
        // if(n<0)
        //     return 0;
        
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
        return funct(nums.size(),nums);
    }
};