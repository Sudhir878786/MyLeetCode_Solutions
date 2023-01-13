class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums1.size();j++){
               mp[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums1.size();j++)
            {
                int sum=-(nums3[i]+nums4[j]);
                ans+=mp[sum];
            }
        }
        return ans;
    }
};