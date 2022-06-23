class Solution {
public:
  
  bool dfs(int s,vector<bool>&vis,vector<bool>& cur,vector<int> p[]){
    vis[s]=true;
    cur[s]=true;
    for(auto a:p[s]){
        if(vis[a]==false){
            if(dfs(a,vis,cur,p)){
                return true;
         }
        }
        else if(vis[a]&&cur[a]){
            return true;
        }
    }
    cur[s]=false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& p) {
    int n=numCourses;
    vector<bool>vis(numCourses,false),cur(numCourses,false);
   vector<int>pi[n];
    for(auto x:p){
        vector<int>data=x;
        int a=data[0];
        int b=data[1];
        pi[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,vis,cur,pi))
                return false;
        }
    }
    return true;
}
};