class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&curpath,int i)
    {  curpath.push_back(i);
        if(i==graph.size()-1)ans.push_back(curpath);
     else{
         for(auto x:graph[i]){
             
             dfs(graph,ans,curpath,x);
         }
     }
     curpath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>curpath;
        dfs(graph,ans,curpath,0);
        return ans;
    }
};