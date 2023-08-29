class Solution
{
    public:
        void func(string & nums)
        {
            int n = nums.size();
            int piv = -1;
            for (int i = n - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    piv = i;
                    break;;
                }
            }
            for (int i = n - 1; i >= piv; i--)
            {
                if (piv != -1)
                {
                    if (nums[i] > nums[piv])
                    {
                        swap(nums[i], nums[piv]);
                        break;
                    }
                }
            }
            reverse(nums.begin() + piv + 1, nums.end());
        }
    int nextGreaterElement(int n)
    {
       	// if(n==1 || n==2 ||n==3 || n==4 || n==5|| n==6||n==7||n==8||n==9){
       	//     return -1;
       	// }
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};