class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int n=diff.size();
        for(int i=0;i<n;i++)
            jobs.push_back({diff[i],profit[i]});
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        
        int wn=worker.size();
        int ans=0;
        int cp=0;
        int cj=0;
        for(int i=0;i<wn;i++){
            while(cj<n and jobs[cj].first<=worker[i]){
                cp=max(cp,jobs[cj].second);
                cj++;
            }
            ans+=cp;
        }
        return ans;
    }
};