class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans{0};
        int postfix=accumulate(nums.begin(),nums.end(),0);
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            postfix-=nums[i];
            if(postfix==prefix){
                return i;
                break;
            }
            prefix+=nums[i];
            
        }
        return -1;
    }
};