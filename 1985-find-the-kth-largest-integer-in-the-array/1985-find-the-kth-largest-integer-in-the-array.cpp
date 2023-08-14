class Solution {
public:
    static bool comp(string& a, string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        for(int i=n-1;i>=0;i--)
        {
            k--;
            if(k==0){
                return nums[i];
            }
        }
        return "";
    }
};