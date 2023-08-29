class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones=0;
        int twos=0;
        for(auto it:nums){
            ones=(ones^it)&(~twos);
            twos=(twos^it)&(~ones);
        }
        return ones;
        
        
        
    }
};