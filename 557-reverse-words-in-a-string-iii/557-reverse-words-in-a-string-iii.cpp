class Solution {
public:
   string reverseWords(string s) {
        int n=s.length();
        int i;
        string ans="";
        
        for(i=0;i<n;i++)
        {
            string t="";
                
            while(i<n && s[i]!=' ')
                t+=s[i++];
            
            if(t.size()>0)
            {
                reverse(t.begin(),t.end());
                ans+=t;
                ans+=' ';
            }
        }

        ans.pop_back();
        return ans;
    }
};