class Solution {
public:
    string breakPalindrome(string pal) {
        if(pal.size()<2) return "";
        for(int i=0;i<pal.size()/2;i++){
            if(pal[i]!='a'){
                pal[i]='a';
               return pal;
            }
             
        }
        pal[pal.size()-1]='b';
        return pal;
    }
};