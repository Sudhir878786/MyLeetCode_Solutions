class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pref(nums.size(),1),suff(nums.size(),1);
        int n=nums.size();
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            suff[i]=suff[i]*pref[i];
        }
        return suff;
       
    }
};