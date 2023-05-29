//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int>ans;
		map<int,vector<int>>mp;
		for(int i=0;i<N;i++){
		    for(int j=0;j<N;j++){
		        mp[i+j].push_back(A[i][j]);
		    }
		}
		for(auto it:mp){
		    for(auto x:it.second){
		      //  cout<<x<<endl;
		      ans.push_back(x);
		    }
		}
// 		reverse(ans.begin(),ans.end());
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
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends