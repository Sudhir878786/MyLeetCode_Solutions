class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int>count(1000000,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                count[abs(nums[i]-nums[j])]++;
            }
        }
        for(int i=0;i<1000000;i++){
            if(count[i]>=k){
                return i;
            }
            k-=count[i];
        }
        return 0;
    }
};