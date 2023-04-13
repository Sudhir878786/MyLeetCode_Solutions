class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        // for(int i=0;i<nums.size(); i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             ans++;
        //         }
        //     }
        // }
        unordered_map<int,int>mp;
        for(auto it:nums){
            ans+=mp[it]++;
        }
        return ans;
    }
};