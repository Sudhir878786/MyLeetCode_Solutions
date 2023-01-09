class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        map<int, int> mp;
        int target = nums.size() / 3;
        for(int i : nums)
            mp[i]++;
        for(auto i : mp)
            if(i.second > target)
                result.push_back(i.first);
        return result;
    }
};