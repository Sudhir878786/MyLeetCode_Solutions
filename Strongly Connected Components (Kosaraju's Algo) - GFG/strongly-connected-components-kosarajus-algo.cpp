//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it])
	        {
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	    
	}
	void func(int cur,vector<int>&vis,vector<vector<int>>&adjt)
	{
	    vis[cur]=1;
	    for(auto it:adjt[cur]){
	        if(!vis[it]){
	            func(it,vis,adjt);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        // }
        // for(int i=0;i<order.size();i++){
        //     cout<<order[i]<<" ";
        // }
        // cout<<endl;
        // now transpose the graph edges
        vector<vector<int>>adjt(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i])
            {
                adjt[it].push_back(i);
            }
        }
        int ans=0;
        while(!st.empty()){
            auto cur=st.top();
            st.pop();
            if(!vis[cur]){
                ans++;
                func(cur,vis,adjt);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends