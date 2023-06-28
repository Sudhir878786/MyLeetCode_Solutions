class Solution {
public: 
    //         vector<vector<int>>mat(m+1,vector<int>(n+1));
//         vector<int>ans(m*n);
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                ans[(i-1)*n + (j-1)] = mat[i][j]=i*j;
//             }
//         }
//        // for(int i=1;i<=m;i++){
//        //      for(int j=1;j<=n;j++){
//        //          cout<<mat[i][j]<<" ";
//        //      }
//        //     cout<<endl;
//        // }

//         // for(int i=0;i<ans.size();i++){
//         //     cout<<ans[i]<<" ";
//         // }
//         // cout<<endl;
//         sort(ans.begin(),ans.end());
//         return ans[k-1];
    int findKthNumber(int m, int n, int k) {
      int i=1;
        int j=m*n;
        while(i<j){
            int mid=(i+j)/2;
            int count=0;
            for(int i=1;i<=m;i++){
                count+=min(n,mid/i);
            }
            if(count<k){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i;
        
    }
};