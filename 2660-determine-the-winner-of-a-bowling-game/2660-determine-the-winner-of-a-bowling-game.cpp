class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int a = 0, b = 0;
        for(int i = 0; i < p1.size(); i++) {
            if(i == 0) {
                a += p1[i];
                b += p2[i];
            }
            else {
                if(i == 1) {
                    if(p1[i - 1] == 10) a += (2 * p1[i]);
                    else a += p1[i];
                    if(p2[i - 1] == 10) b += (2 * p2[i]);
                    else b += p2[i];
                }
                else {
                    if(p1[i - 1] == 10 || p1[i - 2] == 10) a += (2 * p1[i]);
                    else a += p1[i];
                    if(p2[i - 1] == 10 || p2[i - 2] == 10) b += (2 * p2[i]);
                    else b += p2[i];
                }
            }
        }
        if(a > b) return 1;
        if(a < b) return 2;
        return 0;
    }
};