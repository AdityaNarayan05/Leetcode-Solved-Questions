class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        
        int src=image[sr][sc];
        dfs(image,sr,sc,color,image.size(),image[0].size(),src);
        return image;
    }
    void dfs(vector<vector<int>> &img,int sr,int sc,int color,int r,int c,int src){
        if(sr<0 or sr>=r or sc<0 or sc>=c)
            return;
        else if(img[sr][sc]!=src)
            return;
        
        img[sr][sc]=color;
        dfs(img,sr-1,sc,color,r,c,src);
        dfs(img,sr+1,sc,color,r,c,src);
        dfs(img,sr,sc-1,color,r,c,src);
        dfs(img,sr,sc+1,color,r,c,src);
    }
};