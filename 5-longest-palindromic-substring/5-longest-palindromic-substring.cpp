class Solution {
public:
    string longestPalindrome(string S) {
       int n=S.size();
        int l,h;
        int start=0,end=1;
        for(int i=0;i<n;i++){
            l=i-1;
            h=i;
            while(l>=0&&h<n&&S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
            l=i-1;
            h=i+1;
             while(l>=0 && h<n && S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
             }
             
        }
          string t=S.substr(start,end);
           return t;
    
        
    }    
};