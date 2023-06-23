class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    vector<vector<string>> ans;
    
    void solve(int c,vector<string> &board,vi &lR,vi &uD,vi &lD,int n){
        if(c == n){
            ans.push_back(board);
            return;
        }
        
        for(int r=0;r<n;r++)
            if(lR[r]==0 && lD[r+c]==0 && uD[n-1+c-r]==0){
                board[r][c]='Q';
                lR[r]=1;
                lD[r+c]=1;
                uD[n-1+c-r]=1;
                
                solve(c+1,board,lR,uD,lD,n);
                
                board[r][c]='.';
                lR[r]=0;
                lD[r+c]=0;
                uD[n-1+c-r]=0;
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        vi lR(n,0),uD(2*n-1,0),lD(2*n-1,0);
        
        solve(0,board,lR,uD,lD,n);
        return ans;
    }
};