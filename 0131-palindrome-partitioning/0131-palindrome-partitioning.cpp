class Solution {
public:
    vector<vector<string>>ans;
    bool ispal(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void func(string &s,int ind,vector<string>&cur)
    {
        if(ind==s.size()){
            ans.push_back(cur);
            return;
        }
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(ispal(temp)){
                cur.push_back(temp);
                func(s,i+1,cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>cur;
        func(s,0,cur);
        return ans;
    }
};