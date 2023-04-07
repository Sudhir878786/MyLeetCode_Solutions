//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
           //return vector with correct order of elements
        int farr[n+m];
        int k=0;
        for(int i=0;i<n;i++)
        {
            farr[k]=arr1[i];
            k++;
        }
        
        for(int i=0;i<m;i++)
        {
            farr[k]=arr2[i];
            k++;
        }
        
        set<int> st;
        for(int i=0;i<(n+m);i++)
        {
            st.insert(farr[i]);
        }
        
        vector<int> ans;
        for(auto x:st)
            ans.push_back(x);   
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends