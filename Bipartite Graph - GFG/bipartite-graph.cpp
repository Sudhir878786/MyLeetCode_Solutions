//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
   bool dfs(vector<int>adj[],int i,vector<int>&col,int c)
{
  col[i] = c;
  for(auto it:adj[i])
  {
      if(col[it]==-1)
      {
          if(!dfs(adj,it,col,!c)) return false;
      }
      else if(col[it]==c)
          return false;
  }
  return true;
}
bool isBipartite(int V, vector<int>adj[]){
    // Code here
  vector<int>col(V,-1);
  for(int i=0;i<V;i++)
  {
      if(col[i]==-1)
      {
          if(!dfs(adj,i,col,0)) return false;
      }
  }
  return true;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends