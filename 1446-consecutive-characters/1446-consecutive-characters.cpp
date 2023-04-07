class Solution {
public:
    int maxPower(string s) {
       int count=0, ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                count=0;
            }
            ans=max(ans,count);
        }
        return ans+1;
        
    }
};