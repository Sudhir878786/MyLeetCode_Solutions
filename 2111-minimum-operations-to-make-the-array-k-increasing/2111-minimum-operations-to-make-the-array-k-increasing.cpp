class Solution {
public:
    /* for k=2 
          arr=0 2 4 6 ..
          arr=1 3 5 7 ..
       for k=3
          ar=0 3 6 9 ..
          arr=1 4 7 10..
          arr 2 5 8 11..
          
          len(arr)-LIS(arr[:k:]);
    
    */
int func(vector<int>&nums){
          vector<int> lis;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (lis.empty() || lis[lis.size() - 1] <= x) { 
                lis.push_back(x);
                nums[i] = lis.size();
            } else {
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin(); 
                lis[idx] = x; 
                nums[i] = idx + 1;
            }
        }
        // cout<<lis.size()<<endl;
        return lis.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
       int n = arr.size();
        int ans=0;
        for(int i=0;i<k;i++){
            vector<int>nums;
            for(int j=i;j<arr.size();j+=k){
                nums.push_back(arr[j]);
            }
            ans+=nums.size()-func(nums);
        }
        return ans;
    }
};