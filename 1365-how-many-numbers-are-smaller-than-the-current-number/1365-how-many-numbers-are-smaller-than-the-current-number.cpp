class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
            }

        }
        for(auto it=mp.begin();it!=mp.end();it++){
            cout<<it->first<<"->"<<it->second<<endl;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = mp[nums[i]];
        }
    
        return nums;
        
    }
};