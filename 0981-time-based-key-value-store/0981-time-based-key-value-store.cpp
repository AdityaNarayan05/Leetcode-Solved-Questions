class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>> mp;
    TimeMap() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    static bool sort(const pair<int , string> &a , const pair<int , string> &b){
        return a.first > b.first;
    }
    
    void set(string key, string val, int ts) {
        mp[key].push_back({ts , val});
    }
    string get(string key, int ts) {   
        auto &h = mp[key];
        auto ans = lower_bound(h.rbegin() , h.rend() , pair<int , string>{ts,""} , sort);
        if(ans == h.rend())
            return "";
        else
            return (*ans).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */