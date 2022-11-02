class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr)
        {
            long long ans = 0;
            int sum = 0;
            int odd = 0;
            int even = 0;
            for (auto x: arr)
            {
                sum += x;
                if (sum % 2 == 0)
                {
                    ans += odd;
                    even++;
                }
                else
                {
                    ans += 1 + even;
                    odd++;
                }
            }
            return ans % 1000000007;
        }
};