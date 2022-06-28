class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
      for(auto it:s){
        mp[it]++;
      }
      set<int>st;
      int count=0;
      for(auto[i,j]:mp){
        while(st.find(j)!=st.end()){
          j--;
          count++;
        }
        if(j>0){
          st.insert(j);
        }
      }
      return count;
    }
};