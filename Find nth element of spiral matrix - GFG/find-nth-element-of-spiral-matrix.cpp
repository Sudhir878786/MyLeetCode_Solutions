//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int a[MAX][MAX], int n, int m, int k)
{
//Your code here
vector<int>ans;
int left=0;
        int right=m-1;
        int top=0;
        int down=n-1;
        while(left<=right and  top<=down)
        {
            for(int i= left;i<=right;i++){
                ans.push_back(a[top][i]);
            }
            top++;
            for(int i=top;i<=down;i++){
                ans.push_back(a[i][right]);
            }
            right--;
            if(top<=down){
                for(int i=right;i>=left;i--){
                    ans.push_back(a[down][i]);
                }
                down--;
                
            }
            if(left<=right){
                for(int i=down;i>=top;i--){
                    ans.push_back(a[i][left]);
                }
                left++;
            }
        }
        // sort()
        return ans[k-1];
}

