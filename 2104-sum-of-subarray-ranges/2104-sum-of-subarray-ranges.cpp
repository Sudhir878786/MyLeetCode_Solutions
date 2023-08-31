class Solution
{
    public:
        long long subArrayRanges(vector<int> &nums)
        {
           
           	//         long ans = 0;
           	//     for (int i = 0; i < n; i++)
           	//     {
           	//         int mx = A[i], mn = A[i];
           	//         for (int j = i + 1; j < n; j++)
           	//         {
           	//             mx = max(mx, A[j]);
           	//             mn = min(mn, A[j]);

           	//             ans += (mx - mn);
           	//         }
           	//     }
           	//     return ans;
            int n = nums.size();
            stack<int> st;
            vector < long long > min_l(n, 0), max_l(n, 0), min_r(n, 0), max_r(n, 0);
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && nums[st.top()] > nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    min_l[i] = i + 1;
                }
                else
                {
                    min_l[i] = i - st.top();
                }
                st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && nums[st.top()] >= nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    min_r[i] = n - i;
                }
                else
                {
                    min_r[i] = st.top() - i;
                }
                st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && nums[st.top()] < nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    max_l[i] = i + 1;
                }
                else
                {
                    max_l[i] = i - st.top();
                }
                st.push(i);
            }
            while (!st.empty()) st.pop();
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && nums[st.top()] <= nums[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    max_r[i] = n - i;
                }
                else
                {
                    max_r[i] = st.top() - i;
                }
                st.push(i);
            }
            long long ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += (long) nums[i] *(max_l[i] *max_r[i] - min_l[i] *min_r[i]);
            }
            return ans;
        }
};