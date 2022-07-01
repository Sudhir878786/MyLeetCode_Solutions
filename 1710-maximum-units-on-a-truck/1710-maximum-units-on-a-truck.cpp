class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxes, int n) {
        sort(begin(boxes), end(boxes), cmp);
        int ans = 0;
        for(auto box : boxes){
            int left = min(box[0], n);
            ans += left*box[1];
            n -= left;
            if(n==0)
                break;
        }
        return ans;
    }
};