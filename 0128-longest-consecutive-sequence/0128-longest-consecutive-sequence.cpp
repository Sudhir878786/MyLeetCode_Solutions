class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1;
        int count=1;
        if(nums.size()==0)return 0;
        sort(begin(nums),end(nums));
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1)count++;
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        return max(ans,count);
        
    }
};