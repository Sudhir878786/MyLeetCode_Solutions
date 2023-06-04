class Solution {
public:
  
    
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        int f,l;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                f=i;
            }
            else if(nums[i]==nums.size()){
                l=i;
            }
        }
        int ans= f+(n-1-l);
        if(f>l)ans-=1;
        return ans;
    }
};