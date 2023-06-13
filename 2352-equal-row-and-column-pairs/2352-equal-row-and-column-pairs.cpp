
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> b;
        
        for(int j=0;j<grid[0].size();j++){
              vector<int> a;  
              for(int i=0;i<grid.size();i++){
                  
                  a.push_back(grid[i][j]);
                  b.push_back(a);
              }
        }
        // for(int i=0;i<b.size();i++){
        //     for(int j=0;j<b[0].size();j++){
        //         cout<<b[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int n=0;
        for(int i=0;i<grid.size();i++)
           for(int j=0;j<b.size();j++)
             if(grid[i]==b[j]) {n++;}
        return n;
    }
};