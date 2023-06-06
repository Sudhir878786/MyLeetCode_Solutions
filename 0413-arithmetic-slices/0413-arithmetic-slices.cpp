class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> st;
        if(n<3)return 0;
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                vector<int> cur(nums.begin() + i, nums.begin() + j + 1);
                int diff = cur[1] - cur[0];
                
                bool isArithmetic = true;
                for (int k = 2; k < cur.size(); k++) {
                    if (cur[k] - cur[k - 1] != diff) {
                        isArithmetic = false;
                        break;
                    }
                }
                
                if (isArithmetic) {
                    st.push_back(cur);
                    ans++;
                } else {
                    break;  
                }
            }
        }
        
//         for (int i = 0; i < st.size(); i++) {
//             for (int j = 0; j < st[i].size(); j++) {
//                 cout << st[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        return st.size();
    
        }
};