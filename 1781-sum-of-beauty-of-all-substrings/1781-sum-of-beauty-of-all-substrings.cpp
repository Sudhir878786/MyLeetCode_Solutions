class Solution {
public:
    int func(unordered_map<char,int>&mp)
    {
        int l=INT_MAX;
        int h=-1;
        for(auto it:mp){
            h=max(h,it.second);
            if(it.second>=1){
                l=min(l,it.second);
            }
        }
        return h-l;
    }
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                ans+=func(mp);
            }
        }
        return  ans;
    }
};