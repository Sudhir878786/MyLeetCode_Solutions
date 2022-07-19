
   


class Solution {
public:
  
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        // allocate enough space for BIT of range [1, 20001] 
        vector<int> bit(20002, 0);
        for (int i = nums.size() - 1; i >= 0 ; i--) {
            // get count that less or equals num-1 by BIT, (plus 10001 to move number range to [1, 20001])
            for (int j = nums[i] + 10000; j > 0; j -= j & -j) {  
                ans[i] += bit[j];
            }
            // update count in BIT, (plus 10001 to move number range to [1, 20001])
            for (int j = nums[i] + 10001; j < bit.size(); j+= j & -j) {
                bit[j]++;
            }
        }
        return ans;
        
    }
};