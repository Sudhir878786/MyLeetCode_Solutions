class Solution {
public:
    int dp[1001][1001];
   int is_palin(string str, int i, int j)
    {
        int count = 0;
        
        while(i <= j)
        {
            if(str[i] != str[j])
            {
                count++;
            }
            
            i++;
            
            j--;
        }
        
        return count;
    }
    
    int helper(string &str, int i, int n, int k)
    {
        // base case
        
        if(i == n && k == 0)
            return 0;
        
        if(k < 0)
            return INT_MAX;
        
        // if already calculated
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        long long mini = INT_MAX;
        
        // partition at j and find the no. of change needed for being palindrome and call for next
        
        for(int j = i; j < n; j++)
        {   
            long long change_needed = is_palin(str, i, j);
            
            long long ans = change_needed + helper(str, j + 1, n, k - 1);
            
            mini = min(mini, ans);
        }
        
        // store the res and return it
        
        return dp[i][k] = mini;
    }
    
    int palindromePartition(string str, int k) {
        
        int n = str.size();
        
        // initialize dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        return helper(str, 0, n, k);
    }
};
