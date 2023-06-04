class Solution {
public:
    int minimizedStringLength(string s) {
        set<char>ans;
        for(auto it:s){
            ans.insert(it);
        }
        
        return ans.size();
    }
};