class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
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