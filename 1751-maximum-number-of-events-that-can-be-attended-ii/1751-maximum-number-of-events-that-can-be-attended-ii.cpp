class Solution {
public:
    int func(int ind,int n,vector<vector<int>>&e,int k,vector<vector<int>>&dp)
    {
        if(ind ==n || k==0){
            return 0;
        }
        if(dp[ind][k]!=-1){return dp[ind][k];
                          }
        // do not want to attend the event
        int donot=func(ind+1,n,e,k,dp);
        // want to atttend
        int attend=e[ind][2];   // add the current value if attending;
        //  now we need to find the next event whichh can be attendded  for which the starting day of next event should be greated than the current one
        int j=ind;
        while(j<n){
            if(e[j][0]>e[ind][1]){
                break;
            }
            j++;
        }
        if(j<n){
            // found the next attending event
            attend+=func(j,n,e,k-1,dp);
        }
        return dp[ind][k]= max(attend,donot);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return func(0,n,events,k,dp);
    }
};