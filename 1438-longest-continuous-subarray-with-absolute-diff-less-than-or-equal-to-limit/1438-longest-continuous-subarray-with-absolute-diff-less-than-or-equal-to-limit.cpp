class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         multiset<int>st;
        int j=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[j++]));
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};