class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' and !a.empty()){
                a.pop_back();
            }
            else{
               if(s[i]!='#') a+=s[i];
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' and !b.empty()){
                b.pop_back();
            }
            else{
                
                if(t[i]!='#')   b+=t[i];
            }
        }
        return a==b;
    }
};