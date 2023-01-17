class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=0;
        int one=0,zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero++;
            }else {
                one++;
            }
            if(zero>one){
                zero=one;
            }
        }
        return  min(zero,one);
    }
};