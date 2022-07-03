class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=1,m=1;
        for(int i=1;i<nums.size();i++){
          if(nums[i]>nums[i-1])n=m+1;
          else if(nums[i]<nums[i-1])m=n+1;
        }
      return max(n,m);
    }
};