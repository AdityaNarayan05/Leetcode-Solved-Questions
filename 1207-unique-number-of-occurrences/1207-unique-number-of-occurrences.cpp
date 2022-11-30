class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto ar:arr){
            mp[ar]++;
        }
        vector<int> temp;
        for(auto it=mp.begin();it!=mp.end();it++){
            temp.push_back(it->second);
        }
        sort(temp.begin(),temp.end());
        for(int i=1;i<temp.size();i++){
            if(temp[i-1]==temp[i])
                return false;
        }
        return true;
    }
};