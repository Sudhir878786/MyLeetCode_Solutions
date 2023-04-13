class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       int ans=0;
        unordered_set<char>st(begin(jewels),end(jewels));
        for(auto it:stones){
            if(st.count(it)){
                ans++;
            }
        }
        return ans;
    }
};