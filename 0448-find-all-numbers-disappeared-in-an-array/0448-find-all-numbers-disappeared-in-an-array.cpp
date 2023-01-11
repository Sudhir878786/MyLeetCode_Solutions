class Solution {
public:
vector<int> findDisappearedNumbers(vector<int>& nums) {
    set<int> s;
    for (int i = 1; i <= nums.size(); i++) {
        s.insert(i);
    }
    for (int num : nums) {
        s.erase(num);
    }
    return vector<int>(s.begin(), s.end());
    }

};