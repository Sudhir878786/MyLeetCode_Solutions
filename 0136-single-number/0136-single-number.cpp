class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=accumulate(begin(nums),end(nums),0,bit_xor<int>());
        return ans;
        
    }
};