// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
     int cnt_a = __builtin_popcount(a);
        int cnt_b = __builtin_popcount(b);
        int num = 0;
        if(cnt_a >= cnt_b){
            num = a;
            int tmp = cnt_a-cnt_b, i=0;
            while(tmp){
                if((1&(num>>i)) == 1){
                    num ^= (1<<i);
                    tmp -= 1;
                }
                i += 1;
            }
        }
        else{
            num = a;
            int tmp = cnt_b-cnt_a, i=0;
            while(tmp){
                if((1&(num>>i)) == 0){
                    num |= 1<<i;
                    tmp -= 1;
                }
                i += 1;
            }
        }
        return num;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends