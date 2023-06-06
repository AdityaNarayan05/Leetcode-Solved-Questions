class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_map<int,int> mp;
        
        for(auto &it : arr){
            maxi=max(maxi,it);
            mini=min(mini,it);
            mp[it]++;
        }
        
        if((maxi-mini)%(n-1)!=0)
            return false;
        int d=(maxi-mini)/(n-1);
        
        while(n--){
            if(!mp[maxi])
                return false;
            maxi-=d;
        }
        return true;
    }
};