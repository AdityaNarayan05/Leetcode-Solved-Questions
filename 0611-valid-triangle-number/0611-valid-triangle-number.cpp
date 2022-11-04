class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    cnt+=r-l;
                    r--;
                }else
                    ++l;
            }
        }
        return cnt;
    }
};