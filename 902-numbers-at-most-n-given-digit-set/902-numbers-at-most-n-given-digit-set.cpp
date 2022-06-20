class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& d, int n) {
    string s = to_string(n);
    int m= s.size(),dsize=d.size(),ans=0;
        for(int i =1;i<m;i++){
            ans+=pow(dsize,i);
        }
        for(int i=0;i<m;i++){
            bool c=false;
            for(string &r:d){
                if(r[0]<s[i]){
                    ans+=pow(dsize,m-i-1);
                    
                }
                else if(r[0]==s[i]){
                    c=true;
                }
                
            }
            if(!c) return ans;
        }
        return ans+1;
    }
};