class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {  
        int n=board.size(),lbl=1;
        vector<pair<int,int>> cells(n*n+1);
        vector<int> col(n);
        iota(col.begin(),col.end(),0);
        for(int row=n-1;row>=0;row--){
            for(int c:col){
                cells[lbl++]={row,c};
            }
            reverse(col.begin(),col.end());
        }
        vector<int> dist(n*n+1,-1);
        dist[1]=0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int next=curr+1;next<=min(curr+6,n*n);next++){
                auto [row,column]=cells[next];
                int dest=board[row][column]!=-1?board[row][column]:next;
                if(dist[dest]==-1){
                    dist[dest]=dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};