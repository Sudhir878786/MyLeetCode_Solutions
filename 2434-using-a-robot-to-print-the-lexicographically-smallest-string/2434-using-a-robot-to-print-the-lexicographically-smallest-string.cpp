class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        multiset<char>mst;
        stack<char>st;
        for(auto it:s){
            mst.insert(it);
        }
        int i=0;
        string ans="";
        while(i<n){
            while(!st.empty() and *mst.begin()>=st.top()){
                ans+=st.top();
                st.pop();
                cout<<"ans"<<endl;
            }
            st.push(s[i]);
            mst.erase(mst.find(s[i]));
            i++;
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
    }
};