class TopVotedCandidate {
public:
    unordered_map<int,int> mp;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=persons.size();
        int lead=-1;
        unordered_map<int, int> count;
        this->times=times;
        for(int i=0;i<n;i++){
            lead=++count[persons[i]]>=count[lead]?persons[i]:lead;
            mp[times[i]]=lead;
        }
    }
    
    int q(int t) {
        return mp[*--upper_bound(times.begin(),times.end(),t)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */