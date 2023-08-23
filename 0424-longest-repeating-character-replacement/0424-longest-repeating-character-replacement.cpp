class Solution {
public:
    // so we will create a dynamic sliding window (0--->n)
    // count each freq and find the max freq in current iteration
    // now if the cur window len - the max freq is > k
    // means if we find more replacable char than k in window
    // we shrink the window;
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int j=0;
        int i=0;
        int maxx=INT_MIN;
        int n=s.size();
        while(j<n ){
            mp[s[j]]++;
            maxx=max(maxx,mp[s[j]]);
            int curlen=j-i+1;
            if((curlen-maxx)>k){
                // we find more than k replaceble char
                mp[s[i]]--;
                i++;
            }
            curlen=j-i+1;
            ans=max(ans,curlen);
            j++;
        }
        return ans;
    }
};