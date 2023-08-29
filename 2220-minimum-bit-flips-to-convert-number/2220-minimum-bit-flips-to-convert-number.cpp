class Solution {
public:
    int minBitFlips(int start, int goal) {
        // return __builtin_popcount(start^goal);
        int n=start^goal;
        int cnt=0;
        while(n!=0){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
};