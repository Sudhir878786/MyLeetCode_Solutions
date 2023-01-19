class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        int ans=0;
        for(auto it:nums){
            sum=(sum+it)%k;
            // cout<<sum<<endl;
            if(sum<0)sum+=k;
            if(mp.count(sum)){
                ans+=mp[sum];
            }
            mp[sum]++;

        }
        return ans;
    }
};