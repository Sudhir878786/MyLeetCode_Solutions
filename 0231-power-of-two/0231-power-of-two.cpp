class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
           	// if(n==0){
           	//     return 0;
           	// }
           	// while(n!=1){
           	//     if(n%2!=0){
           	//         return false;
           	//     }
           	//     n/=2;
           	// }
           	// return true;
            if(n==0){
                return false;
            }
            if ((long long)(n & ((long long)n - 1)) == 0)
            {
                return true;
            }
            return false;
        }
};