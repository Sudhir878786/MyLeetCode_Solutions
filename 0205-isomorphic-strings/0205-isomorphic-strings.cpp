class Solution {
public:
    bool func(string &s,string&t)
    {
        unordered_map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(t[i]!=mp[s[i]]){
                    return false;
                }
            }
            else mp[s[i]]=t[i];
        }
        return true;;
    }
    bool isIsomorphic(string s, string t) {
       return func(s,t) and func(t,s);
    }
};