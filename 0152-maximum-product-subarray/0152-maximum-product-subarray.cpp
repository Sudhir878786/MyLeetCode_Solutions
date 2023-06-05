class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int l{1},r{1};
        for(int i=0;i<nums.size();i++){
            l=l*nums[i];
            r=r*nums[nums.size()-1-i];
            ans=max(ans,max(l,r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return ans;
        
    }
};