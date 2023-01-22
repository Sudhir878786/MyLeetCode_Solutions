class Solution {
public:
    bool ispal(int i,int j,string&s){
        while(i<j){
            if(s[i++]!=s[j--]){
                return 0;
            }
        }
        return 1;
    }
    int solve(int ind,string&s,vector<int>&dp)
    {
        if(ind == s.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int cut=INT_MAX;
        for(int i=ind;i<s.size();i++){
            if(ispal(ind,i,s)){
                int temp=1+solve(i+1,s,dp);
                cut=min(cut,temp);
            }
        }
        return dp[ind]=cut;
        
    }
    int minCut(string s) {
        int ans=0;
       
        vector<int>dp(s.size(),-1);
        return  solve(0,s,dp)-1;;
    }
};