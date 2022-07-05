class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
       vector<int>v;
        
        for(int i=0;i<nums.size()/2;i++){
            int a = nums[2*i];
            int b = nums[2*i+1];
            while(a--){
                v.push_back(b);
            }
        }
        return v;
    }
};