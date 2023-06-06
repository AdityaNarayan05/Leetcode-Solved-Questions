class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        int q=nums.size()/3 +1;
        
        for(auto n:nums){
            mp[n]++;
            
            if(mp[n]==q)
                ans.push_back(n);
            if(ans.size()==2)
                break;
        }
        return ans;
    }
};