class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>cur;
        for(auto x:nums){
            if(cur.empty()|| cur.back()<x){
                cur.push_back(x);
            }
            else{
                auto it=lower_bound(cur.begin(),cur.end(),x);
                *it=x;
            }
        }
        return cur.size();
    }
};