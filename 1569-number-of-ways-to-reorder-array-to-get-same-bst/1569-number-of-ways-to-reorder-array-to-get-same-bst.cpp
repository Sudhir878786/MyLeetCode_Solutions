class Solution {
public:
    int ncr(int n,int r)
    {
        vector<vector<int>>dp(n+1,vector<int>(r+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(j==0||j==i){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
                }
            }
        }
        return dp[n][r];
    }
    int func(vector<int>&nums){
        if(nums.size()<=2){
            return 1;
            
        }
        vector<int>left,right;
        int root=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        
        long long lcount=func(left);
        long long rcount=func(right);
        long long cur=(ncr(nums.size()-1,left.size())*lcount)%1000000007;
        long long res=(cur*rcount)%1000000007;
        return res;
    }
    int numOfWays(vector<int>& nums) {
        int ans=func(nums);
        return ans-1;
    }
};