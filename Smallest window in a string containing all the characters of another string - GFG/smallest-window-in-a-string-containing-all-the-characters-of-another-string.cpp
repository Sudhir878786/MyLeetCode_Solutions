//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>mp(26,0);
        for(auto it:p)
        {
            mp[it-'a']++;
        }
        int ans=INT_MAX;
        int end=0,start=0;
        int min_start=0;
        int cnt=p.size();
        while(end<s.size()){
            if(mp[s[end]-'a']>0){
                cnt--;
            }
            mp[s[end]-'a']--;
            end++;
            while(cnt==0){
                if(end-start<ans){
                    ans=end-start;
                    min_start=start;
                }
                mp[s[start]-'a']++;
                if(mp[s[start]-'a']>0){
                    cnt++;
                }
                start++;
            }
        }
        if(ans!=INT_MAX){
            return s.substr(min_start,ans);
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends