class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      
        stack<int> st;
        
        for(int i=0; i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-"  && tokens[i]!="*" && tokens[i]!="/")
                st.push(stoi(tokens[i]));
            
            else
            {
                int tp2=st.top();
                st.pop();
                int tp1=st.top();
                st.pop();
                
                if(tokens[i]=="+")
                    st.push(tp1+tp2);
                else if(tokens[i]=="-")
                    st.push(tp1-tp2);
                else if(tokens[i]=="*")
                    st.push(tp1*tp2);
                else
                    st.push(tp1/tp2);
            }
        }
        
        return st.top();
    }
};