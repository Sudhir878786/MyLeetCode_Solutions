class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		int total = accumulate(nums.begin(), nums.end(), 0) - x;
        if(total<0)  return -1;
		int n = nums.size();
		int j = 0;
		int sum = 0;
		int ans = INT_MIN;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			while (sum > total) {
				sum -= nums[j];
				j++;
			}
			if (sum == total) ans = max(ans,(i - j + 1));
		}
		return ans == INT_MIN ? -1 : n- ans;
	}
};