class Solution
{
    public:
        int sumSubarrayMins(vector<int> &arr)
        {
           	//             long long ans = 0;
           	//             long long mod = (long long) 1e9 + 7;
           	//             for (int i = 0; i < arr.size(); i++)
           	//             {
           	//                 int minn = arr[i];
           	//                 for (int j = i; j >= 0; j--)
           	//                 {

           	//                     minn = min(minn, arr[j]);

           	//                     ans += minn % mod;
           	//                 }
           	//             }
           	//             return ans;
            int n = arr.size();

            vector<int> left(n, -1), right(n, n);
           	// for every i find the Next smaller element to left and right

           	// Left
            stack<int> st;
            for (int i = 0; i < n; i++)
            {
                while (st.size() && arr[i] < arr[st.top()]) st.pop();
                if (st.size()) left[i] = i - st.top();
                else left[i] = i + 1;
                st.push(i);
            }

            while (st.size()) st.pop();

           	// Right
            for (int i = n - 1; i >= 0; i--)
            {
                while (st.size() && arr[i] <= arr[st.top()]) st.pop();
                if (st.size()) right[i] = st.top() - i;
                else right[i] = n - i;
                st.push(i);
            }

           	// for(int i=0; i < n; i++) cout << left[i] << " : " << right[i] << endl;
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                long long prod = (left[i] *right[i]) % 1000000007;
                prod = (prod *arr[i]) % 1000000007;
                res = (res + prod) % 1000000007;
            }

            return res % 1000000007;
        }
};