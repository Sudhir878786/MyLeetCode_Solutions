class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      // j-i!=nums[j]-nums[i]
        // nums[i]-i=nums[j]-j
        long long ans=0;
        long long n=nums.size()-1;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-i)!=mp.end()){
                ans+=mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        return (long long)(n*(n+1)/2)- ans;
    }
};