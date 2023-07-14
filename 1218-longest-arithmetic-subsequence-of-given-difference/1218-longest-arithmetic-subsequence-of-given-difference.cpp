class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(auto a:arr){
            int temp=1;
            if(mp.find(a-d)!=mp.end()){
                temp=1+mp[a-d];
            }
            mp[a]=temp;
            ans=max(ans,mp[a]);
        }
        return ans;
    }
};