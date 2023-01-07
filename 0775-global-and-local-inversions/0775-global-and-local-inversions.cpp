class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                swap(nums[i],nums[i-1]);
                i++;
            }
        }
        return is_sorted(nums.begin(),nums.end());
    }
};