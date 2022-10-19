class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>ans;
        vector<pair<int,int>>t;
        for(auto it: mp){
            t.push_back(it);
        }
        sort(t.begin(),t.end(),comp);
        for(int i=0;i<k;i++){
            ans.push_back(t[i].first);   
        }
        return ans;
    }
};