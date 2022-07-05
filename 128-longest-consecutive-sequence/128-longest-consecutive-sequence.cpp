class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
      int len=0;
      for(auto i:nums){
        if(s.count(i-1))continue;
        int ans=1;
        while(s.count(i+1)){
          ans++;
          i++;
        }
        len=max(len,ans);
      }
      return len;
      
    }
};