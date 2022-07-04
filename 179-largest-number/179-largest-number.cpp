class Solution {
public:
   static bool comp(int &a, int &b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return (s1 + s2 > s2 + s1);
    }
    string largestNumber(vector<int> &nums)
    {
        string s = "";
        sort(nums.begin(), nums.end(), comp);
        if (nums[0] == 0)
            return "0";
        for (auto x : nums)
            s += to_string(x);
        return s;
    }
};