class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),i=0,maxReach=0,lastJumped=0,jumps=0;
        
        while(lastJumped<n-1){
            maxReach=max(maxReach,i+nums[i]);
            if(i==lastJumped){
                lastJumped=maxReach;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};