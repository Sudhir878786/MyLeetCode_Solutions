class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy= INT_MAX;
        int sel=0;
        for(int i:prices){
            buy=min(buy,i);
            sel=max(sel,i-buy);
        }
        return sel;
    }
};