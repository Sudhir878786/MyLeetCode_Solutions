class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int n = nums.size();
    int max_sum = nums[0], curr_sum = nums[0];
    int max_start = 0, max_end = 0, curr_start = 0;
    for (int i = 1; i < n; i++) {
        if (curr_sum < 0) {
            curr_sum = nums[i];
            curr_start = i;
        } else {
            curr_sum += nums[i];
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_start = curr_start;
            max_end = i;
        }
    }
    cout << "Subarray with the largest sum: ";
    for (int i = max_start; i <= max_end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return max_sum;

    }
};