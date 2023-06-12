class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        int i=0;
        while(i<n and  s[i]=='a'){
            i++;    
        }
        while(i>=n){
            s[n-1]='z';
            i++;
            return s;
        }
        while(i<n and s[i]!='a'){
            s[i]--;
            i++;
        }
       return s;
    }
};