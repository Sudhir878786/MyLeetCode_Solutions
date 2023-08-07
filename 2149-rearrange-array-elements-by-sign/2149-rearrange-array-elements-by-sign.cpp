class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int od=1;
        int ev=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[od]=nums[i];
                od+=2;
            }
            else{
                ans[ev]=nums[i];
                ev+=2;
            }
        }
        return ans;
    }
};