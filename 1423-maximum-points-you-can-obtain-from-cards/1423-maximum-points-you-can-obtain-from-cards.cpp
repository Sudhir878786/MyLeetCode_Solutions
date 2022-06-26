class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int ans=0;
      for(int i=0;i<k;i++){
        ans+=c[i];
      }
      int cur=ans;
      for(int i=k-1;i>=0;i--){
        cur-=c[i];
        cur+=c[c.size()-k+i];
        ans=max(ans,cur);
      }
      return ans;
    }
};