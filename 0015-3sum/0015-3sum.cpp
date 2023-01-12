class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
           if(i>0 and nums[i]==nums[i-1])continue;
           int j=i+1;
           int k=n-1;
           while(j<k){
               if(nums[i]+nums[j]+nums[k]==0){
                   ans.push_back({nums[i],nums[j],nums[k]});
                   while(j<k and nums[j]==nums[j+1]){
                       j++;
                   }
                   while(j<k and nums[k]==nums[k-1]){
                       k--;
                   }
                   j++;
                   k--;
               }else if(nums[i]+nums[j]+nums[k]<0){
                   j++;
               }else{
                   k--;
               }
           }
       }
        return ans;
    }
};