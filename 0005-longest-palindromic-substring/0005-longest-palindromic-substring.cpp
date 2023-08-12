class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int l,r;
        int start=0,end=1;
        for(int i=1;i<n;i++){
            l=i-1;
            r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>end){
                    start=l;
                    end=r-l+1;
                }
                l--;
                r++;
            }
            l=i-1;
            r=i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>end){
                    start=l;
                    end=r-l+1;
                }
                l--;
                r++;
            }
            
        }
        string ans=s.substr(start,end);
        return ans;
    }
};