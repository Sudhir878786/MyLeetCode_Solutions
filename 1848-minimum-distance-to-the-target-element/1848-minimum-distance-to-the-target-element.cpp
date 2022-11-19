class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target){
                mp[i]=nums[i];
            }
            
        }
        for(auto it:mp){
            ans=min(ans,abs(it.first-start));
        }
    return ans;
        
    }
};