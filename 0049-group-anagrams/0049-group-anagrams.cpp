class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string copy=it;
            sort(it.begin(),it.end());
            mp[it].push_back(copy);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};