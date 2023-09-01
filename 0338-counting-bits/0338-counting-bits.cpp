class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>a;
        int m=0;
        for(int i=0;i<=n;i++){
            m = __builtin_popcount(i);

            a.push_back(m);
        }
        return a;
        
        
    }
};