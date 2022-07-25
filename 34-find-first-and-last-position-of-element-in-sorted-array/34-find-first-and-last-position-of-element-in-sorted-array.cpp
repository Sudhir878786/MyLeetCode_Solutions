class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    // use binary search stl 
    int left = lower_bound(nums.begin(),nums.end(),target) - nums.begin();             // lower_bound for given target  -> it give first occurence
    int right = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;          // upper_bound fir given target  -> if give lase occurecnce next position hence here we substract by '1'
    
    vector<int>v;                // for ouptup
    
    // if target not present in an array then take right and left -1
    if(left==nums.size() || nums[left]!=target){
        left = -1;
        right = -1;
    }
    
    v.push_back(left);
    v.push_back(right);
    
    return v;
}
};