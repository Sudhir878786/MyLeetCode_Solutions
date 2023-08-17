class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        int dirx[]={-1,0,1,0};
        int diry[]={0,1,0,-1};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int x=q.front().first.first;
                int y=q.front().first.second;
                int cost=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int r=x+dirx[i];
                    int c=y+diry[i];
                    if(r>=0 and c>=0 and r<n and c<m and dist[r][c]>dist[x][y]+1){
                        dist[r][c]=dist[x][y]+1;
                        q.push({{r,c},c+1});
                    }
                }
            }
        }
        return dist;
    }
};