class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, int>mp;
        for(auto it : bank)
            mp[it] = 1;
        int ans = 0;
        queue<pair<string , int>> q;
        q.push({start, 0});
        vector<char>gn ={'A', 'C', 'G', 'T'};
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto &cur = q.front();
                q.pop();
                if(cur.first == end)
                    return cur.second;
                int len = cur.first.length();
                for(int k = 0; k <= len; k++){
                    char org = cur.first[k];
                    for(int j = 0; j < 4; j++){
                        cur.first[k] = gn[j];
                        if(mp[cur.first]){
                            q.push({cur.first, cur.second + 1});
                            mp[cur.first]  = 0;
                        }
                    }
                    cur.first[k] = org;
                }
            }
        }
        return -1;
    }
};