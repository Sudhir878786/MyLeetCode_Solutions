class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int pref=1;
        int suff=1;
        for(int i=0;i<nums.size();i++){
            pref*=nums[i];
            suff*=nums[nums.size()-1-i];
            ans=max(ans,max(pref,suff));
            if(pref==0){
                pref=1;
            }
            if(suff==0){
                suff=1;
            }
        }
        return ans;
    }
};