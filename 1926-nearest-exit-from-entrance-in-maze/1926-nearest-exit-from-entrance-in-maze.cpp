class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        int res=0;
        int s1=e[0],s2=e[1];
        queue<pair<int,int>> q;
        maze[s1][s2]='+';
        q.push({s1,s2});
        while(!q.empty()){
            int s=q.size();
            res++;
            for(int k=0;k<s;k++){
                auto j=q.front();
                for(int p=0;p<4;p++){
                    int p1=j.first+dir[p][0],p2=j.second+dir[p][1];
                    if(p1<0 || p2<0 || p1>=n || p2>=m || maze[p1][p2]=='+')
                        continue;
                    if(p1==0||p2==0||p1==n-1||p2==m-1)
                        return(res);
                    maze[p1][p2]='+';
                    q.push({p1,p2});
                }
                q.pop();
            }
        }
        return(-1);
    }
};