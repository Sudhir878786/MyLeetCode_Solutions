class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort (nums.begin(), nums.end());
        
        for (int i = nums.size() -1; i >= 0; i --) {
                k--;
            if (k == 0)
                return nums[i];
        }
        return 0;
    }
};