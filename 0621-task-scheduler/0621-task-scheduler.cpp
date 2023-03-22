class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int cnt=0;
        for(auto job:tasks){
            mp[job]++;
            cnt=max(cnt,mp[job]);
        }
        int ans=(cnt-1)*(n+1);
        for(auto m : mp)
            if(m.second==cnt)
                ans++;
        return max((int)tasks.size(),ans);    
    }
};