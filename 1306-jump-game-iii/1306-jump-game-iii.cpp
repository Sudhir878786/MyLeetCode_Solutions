class Solution {
public:
  bool solve(vector<int>& arr,vector<bool>&vis,int i)
  {
    if(i<0 || i>=arr.size()|| vis[i])return false;
    if(arr[i]==0)return true;
    vis[i]=true;
    return solve(arr,vis,i+arr[i]) || solve(arr,vis,i-arr[i]);
  }
   
    bool canReach(vector<int>& arr, int start) {
      
      vector<bool>vis(arr.size(),false);
      return solve(arr,vis,start);
        
    }
};