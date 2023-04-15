class Solution {
public:
    int distinctAverages(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        unordered_set<double> u;
        int n = nums.size();
        
        for(int i = 0; i < n/2; ++i)
            u.insert((nums[i] + nums[n-i-1]) / 2.0);

        return u.size();
    }

};