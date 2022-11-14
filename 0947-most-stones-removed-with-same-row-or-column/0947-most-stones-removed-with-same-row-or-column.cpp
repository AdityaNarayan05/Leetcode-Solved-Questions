class Solution {
public:
    unordered_map<int,int> mp;
    int islands=0;
    int removeStones(vector<vector<int>>& stones) {
        for(int i=0;i<stones.size();++i)
            funct(stones[i][0],~stones[i][1]);
        
        return stones.size()-islands;
    }
    void funct(int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y)
            mp[x]=y,islands--;
    }
    int find(int x){
        if(!mp.count(x))
            mp[x]=x,islands++;
        if(x!=mp[x])
            mp[x]=find(mp[x]);
        return mp[x];
    }
};