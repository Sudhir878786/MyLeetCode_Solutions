class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
             char a=s[i];
             if(mp.count(a) and mp[s[i]]>=start){
                 start=mp[s[i]]+1;
             }
            mp[s[i]]=i;
            ans=max(ans,i-start+1);
                 
        }
        return ans;
    }
};