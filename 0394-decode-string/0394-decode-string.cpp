class Solution
{
    public:
        string decodeString(string s)
        {
            stack<char> st;
            string ans = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ']')
                {
                    while (!st.empty() and st.top() != '[')
                    {
                        ans = st.top() + ans;
                        st.pop();
                    }
                    if (!st.empty())
                    {
                        st.pop();
                        string dig = "";
                        while (!st.empty() and st.top() >= '0' and st.top() <= '9')
                            

                        {
                            dig = st.top() + dig;
                            st.pop();
                        }
                        int num = stoi(dig);
                        string temp = ans;
                        for (int i = 0; i < num - 1; i++)
                        {
                            ans += temp;
                        }

                        for (int i = 0; i < ans.size(); i++)
                        {
                            st.push(ans[i]);
                        }
                        ans = "";
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
            while (!st.empty())
            {
                ans = st.top() + ans;
                st.pop();
            }
            return ans;
        }
};