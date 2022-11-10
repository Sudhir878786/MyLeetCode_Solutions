class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(auto it:s){
            if(ans.size() and ans.back()==it){
                ans.pop_back();
            }
            else{
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};