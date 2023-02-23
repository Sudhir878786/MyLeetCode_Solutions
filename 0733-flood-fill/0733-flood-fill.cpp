class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int orgcolor)
    {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=orgcolor )return;
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,orgcolor);
        dfs(image,sr+1,sc,color,orgcolor);
        dfs(image,sr,sc-1,color,orgcolor);
        dfs(image,sr,sc+1,color,orgcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]!=color){
            dfs(image,sr,sc,color,image[sr][sc]);
        }
        return image;
    }
};