class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        if(nums.size()<=2){
            return nums.size();
        }
        int prev=1;
        for(int i=2;i<nums.size();i++){
            if(!(nums[i]==nums[prev] and nums[i]==nums[prev-1])){
                nums[++prev]=nums[i];
              
            }
        }
        return prev+1;
    }
};