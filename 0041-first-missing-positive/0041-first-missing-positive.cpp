class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        int n=nums.size();
        vector<bool> exist(n);
        for(auto num:nums)
            if(num>0 and num<=n)
                exist[num-1]=true;
        
        for(int i=0;i<exist.size();i++)
            if(!exist[i])
                return i+1;
        return n+1;
    } 
};