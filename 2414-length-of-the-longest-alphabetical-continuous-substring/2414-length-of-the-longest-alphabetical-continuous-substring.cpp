class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        
        int count=1;
        
        int j=s.size()-1;
        
        for(int i=0;i<s.size();i++){
            int ans=1;
            while(i<j and s[i+1]-s[i]==1){
                ans++;;i++;
               
               
            }
            count=max(ans,count);
        }
        return count;
        
    }
};