//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> ans;
    void permutation(string nums, int i)
    {
        if (i == nums.size())
        {
            ans.insert(nums);
       
        }

        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
		vector<string>find_permutation(string nums)
		{
		    // Code here there
            permutation(nums, 0);
            vector<string> res(ans.begin(), ans.end());
            return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends