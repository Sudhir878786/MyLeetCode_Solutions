class Solution
{
    public:
        int count = 0;

    int findPairs(vector<int> &nums, int k)
    {
//         unordered_set<int> st;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = 0; j < nums.size(); j++)
//                 if (i != j and nums[i] - nums[j] == k)

//                     st.insert(nums[i]);
//         }
//         return st.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(k==0){
                if(it.second>1){
                    count++;
                }
            }
            else if(mp.find(it.first-k)!=mp.end()){
                count++;
            }
        }
        return count;
    }
};