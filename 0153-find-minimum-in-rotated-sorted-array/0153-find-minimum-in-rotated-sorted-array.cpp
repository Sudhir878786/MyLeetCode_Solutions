class Solution {
public:
    // It's a clockwise rotation.
    // There is no 0 rotations.
    
    int findMin(vector<int>& nums) {
        
//         // Linear searching for the minimum element
//         int min_pos = 0;
        
//         for(int i = 0; i < nums.size(); i++) {
//             min_pos = nums[i] < nums[min_pos] ? i : min_pos;
//         }
        
//         // if(min_pos == 0)
//         //     min_pos = nums.size();
        
//         return nums[min_pos];
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};