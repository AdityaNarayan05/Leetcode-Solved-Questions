class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hst;
        for(auto num:nums)
            hst.insert(num);
        
        int ans=0;
        for(auto num:nums){
            if(!hst.count(num-1)){
                int curr=num;
                int cst=1;
                
                while(hst.count(curr+1)){
                    curr++;
                    cst++;
                }
                ans=max(ans,cst);
            }
        }
        return ans;
    }
};