//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
  
   void add_palindrome(string str, int left, int right, unordered_set<string> &st)

    {

        while(left >= 0 && right < str.size() && str[left] == str[right])

        {

            st.insert(str.substr(left, right-left+1));

            left--;

            right++;

        }

    }

  

    int palindromeSubStrs(string s) {

        unordered_set<string> st;

        

        for(int i=0; i<s.size(); i++){

            // odd length palindrome from current index

            add_palindrome(s, i, i, st);

            //even length palindrome from current index

            add_palindrome(s, i, i+1, st);

        }

        

        return st.size();

    
      
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends