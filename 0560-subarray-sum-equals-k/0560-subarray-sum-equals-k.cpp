class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0,sum=0;
        mp[0]=1;
        for(auto it:nums){
            sum+=it;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            
                mp[sum]++;
        }
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<"->"<<it->second<<endl;
        // }
        return ans;
    }
};