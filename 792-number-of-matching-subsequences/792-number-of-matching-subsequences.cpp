class Solution {
public:
    int numMatchingSubseq(string a, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        int ans=0;
        for(auto x:mp){
            string s=x.first;
            int i=0,j=0;
            while(i<s.length() and j<a.length()){
                if(s[i]==a[j]){
                    i++;
                }
                j++;
            }if(i==s.length())ans+=x.second;
            
        }
        return ans;
    }
};