class Solution {
public:
    unordered_set<string>st;
    int a,b,n;
    string ans;
    string rot(string s){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        return s;
    }
    string add(string s){
        for (int i=1; i<n; i += 2) {
            char &c = s[i];
            c = '0' + (c-'0'+a)%10;
        }
        return s;
    }
    void dfs(string s){
        if(st.count(s)) return;
        st.insert(s);
        ans=min(ans,s);
        dfs(rot(s));
        dfs(add(s));
    }
    string findLexSmallestString(string s, int a1, int b1) {
        a=a1,b=b1,n=s.size();
        ans=s;
        dfs(s);        
        return ans;
    }
};