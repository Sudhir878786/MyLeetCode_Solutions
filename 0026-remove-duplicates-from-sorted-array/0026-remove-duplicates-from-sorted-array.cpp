class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        set <int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
       nums.clear();
       for(auto it:s){
            nums.push_back(it);
        }

        return nums.size();
    }


};