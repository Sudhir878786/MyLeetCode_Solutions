class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX;
        int j=INT_MAX;
        for(auto a:nums){
            if(a<i)i=a;
            else if(a<j && i<a) j=a;
            else if(a>j)return 1;
        }
        return 0;
    }
};