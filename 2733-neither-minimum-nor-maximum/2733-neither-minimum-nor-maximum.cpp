class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto &i: nums){
            if((i != nums[0]) && (i != nums[nums.size()-1]))return i;
        }
        return -1;
    }
};