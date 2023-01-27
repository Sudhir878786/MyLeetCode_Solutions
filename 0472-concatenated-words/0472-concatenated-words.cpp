class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            vector<string> res;
    unordered_set<string> set;
    for (string word : words) {
        set.insert(word);
    }
    for (string word : words) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = i + 1; j <= n; j++) {
                if (j - i < n && set.count(word.substr(i, j - i))) {
                    dp[j] = true;
                }
                if (j == n && dp[n]) {
                    res.push_back(word);
                }
            }
        }
    }
        vector<string>ans;
        unordered_set<string>s2;
        for(auto it:res){
            s2.insert(it);
            
        }
        for(auto it:s2){
            ans.push_back(it);
        }
    return ans;
}

};