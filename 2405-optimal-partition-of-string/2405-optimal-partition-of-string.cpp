class Solution {
public:
    int partitionString(string s) {
        set<int>st;
        int ans=1;
        for(auto it:s){
            if(st.find(it)!=st.end())
            {
                ans++;
                st.clear();
            }
            st.insert(it);
        }
        return ans;
    }
};