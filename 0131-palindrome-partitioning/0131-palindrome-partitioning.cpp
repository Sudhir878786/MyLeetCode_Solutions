class Solution {
public:
    bool ispal(string&s)
    {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void func(int ind,vector<string>&cur,string &s,vector<vector<string>>&ans)
    {
        if(ind==s.size()){
            ans.push_back(cur);
            return;
        }
        string now="";
        for(int i=ind;i<s.size();i++){
            now+=s[i];
            if(ispal(now))
            {
                cur.push_back(now);
                func(i+1,cur,s,ans);
                cur.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        func(0,cur,s,ans);
        
        
        return ans;
    }
};