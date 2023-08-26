class Solution {
public:
    int dp[100003][3];
    
    // prev - 0 -> Subarray size is 0
    // Subarray size is not 0
    // prev - 1 -> Last element of subarray was from nums1
    // prev - 2 -> Last element of subarray was from nums2

    int f(int ind, int prev, vector<int> &s , vector<int>& t) {
        if(ind == s.size()) {
            return 0;
        }
        if(dp[ind][prev] != -1)return dp[ind][prev];
        
        int skip = 0, pick1 = 0, pick2 = 0;
        if(prev == 0)skip = f(ind+1, prev, s, t); // skip only when your subarray size is 0

        int val = (prev == 0 ? 0 : prev == 1 ? s[ind-1] : t[ind-1]); // previous value of subarray

        if(prev == 0 || s[ind] >= val) pick1 = 1 + f(ind+1, 1, s, t);
        if(prev == 0 || t[ind] >= val) pick2 = 1 + f(ind+1, 2, s, t);
        
        return dp[ind][prev] =  max({skip, pick1, pick2});
    }
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, nums1, nums2);
    }
};