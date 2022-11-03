class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
       
        for(auto x:words){
            string t=x;
            reverse(t.begin(),t.end());
            if(mp[t]){
                mp[t]--;
                ans+=4;
            }
            else{
                mp[x]++;
            }
            
        }
        for(auto i:mp){
            if(i.second){
                if(i.first[0]==i.first[1]){
                    ans+=2;
                    break;
                }
            }
        }
        
        
        
        return ans;
        
    }
};