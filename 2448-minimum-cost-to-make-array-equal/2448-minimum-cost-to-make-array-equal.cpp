class Solution
{
    public:
       	// see let take eg
        /*
        nums[a,b,c,d]   cost[c1,c2,c3,c4]
        let try to make all element equal to c
        so (c-a)*c1+(c-b)*c2+(c-d)*c4;
        so ans= min of summation(ci)+summation(nums[i]*cost[i]);
        */
        long long minCost(vector<int> &nums, vector<int> &cost)
        {
            long long n = nums.size(), i, j, ans = LLONG_MAX;

            vector<pair < long long, long long>> v(n);

            for (i = 0; i < n; i++)
            {
                v[i] = { nums[i],
                    cost[i]
                };
            }

            sort(v.begin(), v.end());

            vector < long long > lsum(n), rsum(n);
            lsum[0] = 0;
            rsum[n - 1] = 0;
            long long l = v[0].second, r = v[n - 1].second;

            for (i = 1; i < n; i++)
            {
                lsum[i] = lsum[i - 1] + (v[i].first - v[i - 1].first) *l;
                l += v[i].second;

                rsum[n - i - 1] = rsum[n - i] + (v[n - i].first - v[n - i - 1].first) *r;
                r += v[n - i - 1].second;
            }

            for (i = 0; i < n; i++)
            {
                ans = min(lsum[i] + rsum[i], ans);
            }

            return ans;
        }
};