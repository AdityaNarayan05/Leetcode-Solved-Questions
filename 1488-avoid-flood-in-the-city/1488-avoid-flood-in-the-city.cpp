class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        int n=rains.size();
        unordered_map<int,int> full;
        set<int> dd;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                dd.insert(i);
                ans.push_back(1);
            }else{
                int lake=rains[i];
                if(full.find(lake)!=full.end()){
                    auto it=dd.lower_bound(full[lake]);
                    if(it==dd.end())
                        return {};
                    int d=*it;
                    ans[d]=lake;
                    dd.erase(d);
                }
                full[lake]=i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};