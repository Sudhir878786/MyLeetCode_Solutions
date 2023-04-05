class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k = k%nums.size();
        // cout<<k<<endl;
       
        reverse(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        cout<<endl;
    
        reverse(nums.begin(), nums.begin()+k);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        cout<<endl;
        reverse(nums.begin()+k, nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        cout<<endl;
    }
};