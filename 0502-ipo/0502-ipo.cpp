class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> projects(n);
        for(int i=0;i<n;i++)
            projects[i]={capital[i],profits[i]};
        
        sort(projects.begin(),projects.end());
        int i=0;
        priority_queue<int> maxCap;
        
        while(k--){
            while(i<n and projects[i].first <=w){
                cout<<projects[i].second<<" ";
                maxCap.push(projects[i].second);
                i++;
            }
            cout<<endl;
            if(maxCap.empty())
                break;
            cout<<w<<endl;
            w+=maxCap.top();
            maxCap.pop();
        }
        return w;
    }
};