// // class Solution {
// // public:
// //      int is_palin(string str, int i, int j)
// //     {
// //         int count = 0;
        
// //         while(i <= j)
// //         {
// //             if(str[i] != str[j])
// //             {
// //                 count++;
// //             }
            
// //             i++;
            
// //             j--;
// //         }
        
// //         return count;
// //     }
// //     bool func(int ind,int k,string s)
// //     {
// //         if(ind == s.size() and k==0){
// //             return 0;
// //         }
// //         int ans = INT_MAX;
// //         for(int i=ind;i<s.size();i++){
// //             int need=is_palin(s,ind,i);
// //             int cur=need+func(i+1,k-1,s);
// //             ans=min(ans,cur);
// //         }
// //         if(ans!=INT_MAX){
// //             return  true;
// //         }
// //         return false;
// //     }
// //     bool checkPartitioning(string s) {
// //        int n=s.size();
// //         int k=3;
// //         return func(0,k,s);
// //     }
// // };


// class Solution {
//   bool isPalindrome(const string& s, int i, int j) {
//     if (i > j) {
//       return false;
//     }

//     while (i < j) {
//       if (s[i++] != s[j--]) {
//         return false;
//       }
//     }

//     return true;
//   }

//  public:
//   bool checkPartitioning(string s) {
//     for (int i = 0; i < s.size(); ++i) {
//       for (int j = i + 1; j < s.size(); ++j) {
//         if (isPalindrome(s, 0, i) && isPalindrome(s, i + 1, j) &&
//             isPalindrome(s, j + 1, s.size() - 1)) {
//           return true;
//         }
//       }
//     }

//     return false;
//   }
// };



class Solution {
public:
    bool chk(int low, int high, string&s){
        while(low<high){
            if(s[low]!=s[high])return false;
            low++;
            high--;
        }

        return true;
    }

    bool func(int it, string & s, int k, vector<vector<int>>&dp){
        
        if(it == s.size()){
            return k==0;
        }

        if(k == 0)return dp[it][k] = false;

        if(k == 1)return dp[it][k] = chk(it,s.size()-1,s);

        if(dp[it][k]!=-1)return dp[it][k];

        for(int j = it; j<s.size()-k+1;j++){
            if(chk(it,j,s) and func(j+1,s, k-1,dp))return dp[it][k] = true;
        }

        return dp[it][k] = false;
    }

    bool checkPartitioning(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(4, -1));
        return func(0,s,3,dp);
    }
};