class Solution {
public:
    void func(vector<vector<int>>& image, int sr, int sc, int color,int n,int m,int prev)
    {
        if(sr<0 || sc< 0 || sr>=n || sc>=m || image[sr][sc]!=prev){
            return;
        }
        image[sr][sc]=color;
        func(image,sr+1,sc,color,n,m,prev);
        func(image,sr-1,sc,color,n,m,prev);
        func(image,sr,sc+1,color,n,m,prev);
        func(image,sr,sc-1,color,n,m,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]!=color){
            func(image,sr,sc,color,n,m,image[sr][sc]);
        }
        return image;
    }
};