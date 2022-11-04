class Solution {
public:
        bool isvowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        string ans;
        int  i=0;
        int j=s.size()-1;
        while(i<j){
            while(i<s.size() and !isvowel(s[i])){
                i++;
            }
            while(j>=0 and !isvowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i++],s[j--]);
            }
        }
            // cout<<s;
        return s;
    }
};