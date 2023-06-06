class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> ans;
        for(auto i:nums)
            mp[i]++;
        
        
        for(auto &it : mp)
            if(it.second>n/3)
                ans.push_back(it.first);
        
        return ans;
    }
};