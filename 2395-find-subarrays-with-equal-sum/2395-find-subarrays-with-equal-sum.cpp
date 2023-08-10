class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n-1);
        for(int i=1;i<n;i++){
            
            arr[i-1] = nums[i]+nums[i-1];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                if(arr[i] == arr[j])return true;
            }
        }
        return false;
    }
};