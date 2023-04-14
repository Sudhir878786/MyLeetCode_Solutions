class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=start+2*i;
        }
        int res{0};
        for(int i=0;i<n;i++){
            res^=ans[i];
        }
        return res;
    }
};