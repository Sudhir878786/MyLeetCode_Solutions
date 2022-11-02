//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int>row,cols;
            // rows
            row.push_back(-1);
            for(int i=0;i<enemy.size();i++){
                row.push_back(enemy[i][0]-1);
            }
            row.push_back(n);
            sort(row.begin(),row.end());
            int maax=0;
            for(int i=0;i<row.size();i++){
                maax=max(maax,(row[i]-row[i-1])-1);
            }
            
            // cols
            
            cols.push_back(-1);
            for(int i=0;i<enemy.size();i++){
                cols.push_back(enemy[i][1]-1);
            }
            cols.push_back(m);
            sort(cols.begin(),cols.end());
            int mm=0;
            for(int i=0;i<cols.size();i++){
                mm=max(mm,(cols[i]-cols[i-1])-1);
            }
            
            
            
           return mm*maax; 
        }
        
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends