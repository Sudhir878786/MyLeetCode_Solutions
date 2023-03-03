class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            int cur=prices[i]-mini;
            ans=max(ans,cur);
            mini=min(prices[i],mini);
        }
        return ans;
    }
};