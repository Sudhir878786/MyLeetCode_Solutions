//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string ans="";
        stack<char>st;
     
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                // pop till '[' not came
                while(st.size()>0 && st.top()!='[')
                {
                    ans=st.top()+ans;
                    st.pop();
                }
                
                // at this line we have ']' at top so pop it
                if(st.size()!=0)
                  st.pop();
                  
                  // extract digit
                  string number="";
                  while(st.size()>0 && st.top()>='0' && st.top()<='9')
                  {
                      number=st.top()+number;
                      st.pop();
                  }
                  
                  // concate the string 
                  int digit_n=stoi(number);
                  string temp=ans;
                  for(int i=0;i<digit_n-1;i++)
                       ans+=temp;
        
                  //  push all to stack 
                  for(int i=0;i<ans.size();i++)
                      st.push(ans[i]);
                  
                  // reset ans
                  ans="";
            }
            else
              st.push(s[i]);
        }
        while(st.size()>0)
        {
            ans=st.top()+ans;
            st.pop();
        }
      return ans;  
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends