class Solution {
public:
    // furst we will find the xor of all the vec ie left with remainng two element xor
    // now we havec to find the last set bit of that xor
    // now divide in two set grp   last bit set | last bit unset
    vector<int> singleNumber(vector<int>& nums) {
        long long xy=0;
        for(auto it:nums){
            xy^=it;
        }
        // last set bit
        xy&=-xy;
        vector<int>ans={0,0};
        for(auto it:nums){
            if((it&xy)==0){
                ans[0]^=it;
            }
            else{
                ans[1]^=it;
            }
        }
        return ans;
    }
};