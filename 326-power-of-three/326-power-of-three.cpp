class Solution {
public:
    bool isPowerOfThree(int n) {
        return n==0?false:n==pow(3,round(log(n)/log(3)));
    }
};