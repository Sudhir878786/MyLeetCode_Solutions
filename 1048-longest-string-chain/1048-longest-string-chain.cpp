class Solution {
public:
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    bool check(string &s,string &t){
        if(s.size()!=t.size()+1) return false;
        int i = 0,j = 0;
        while(j<s.size()){
            if(s[j]==t[i]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==t.size() && j==s.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int c = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            c = max(c,dp[i]);
        }
        return c;
    }
};