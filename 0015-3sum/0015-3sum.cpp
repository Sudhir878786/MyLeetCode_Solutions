class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            int j=i+1;
            int n=nums.size()-1;
            while(j<n){
                if(nums[i]+nums[j]+nums[n]==0){
                    ans.push_back({nums[i],nums[j],nums[n]});
                    while(j<n and (nums[j]==nums[j+1])){
                        j++;
                    }
                    while(j<n and (nums[n]==nums[n-1])){
                        n--;
                    }
                    j++;
                    n--;
                    
                }
                else if((nums[i]+nums[j]+nums[n])<0){
                    j++;
                }else n--;
            }
        }
        return ans;
    }
};