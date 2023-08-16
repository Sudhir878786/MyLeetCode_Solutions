class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int end=0,start=0;
        int ans=INT_MAX;
        int min_start=0;
        int cnt=t.size();
        for(auto it:t)
        {
            mp[it]++;
        }
        while(end<s.size()){
            if(mp[s[end]]>0){
                cnt--;
            }
            mp[s[end]]--;
            end++;
            while(cnt==0){
                if(end-start<ans){
                    ans=end-start;
                    min_start=start;
                }
                mp[s[start]]++;
                // cout<<s[start]<<endl;
                if(mp[s[start]]>0){
                    cnt++;
                }
                start++;
            }
        }
        if(ans!=INT_MAX){
            return s.substr(min_start,ans);
        }
        return "";
    }
};