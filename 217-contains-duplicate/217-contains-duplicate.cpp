class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set ;
        
        for(int i = 0 ; i <nums.size();i++)
        {
            //if we find the cuurent number in the set,
            //then it's not unique > return true
            if(set.find(nums[i])!=set.end())
                return true;
            
            //if not found, add the number to the set
            set.insert(nums[i]);
        }
        return false;
        
    }
};