class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int>pref,suff;
        pref.push_back(0);
        suff.push_back(0);
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                cnt++;
            }
            pref.push_back(cnt);
            // cout<<pref[i]<<endl;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='Y'){
                cnt++;
            }
            suff.push_back(cnt);
            // cout<<"suff"<<endl;
            // cout<<suff[i]<<endl;
        }
        reverse(suff.begin(),suff.end());
        int maxx=INT_MAX;
        for(int i=0;i<=n;i++){
            int h=pref[i]+suff[i];
            if(h<maxx){
                // cout<<h<<endl;
                maxx=h;
                ans=i;
            }
        }
        return ans;
    }
};