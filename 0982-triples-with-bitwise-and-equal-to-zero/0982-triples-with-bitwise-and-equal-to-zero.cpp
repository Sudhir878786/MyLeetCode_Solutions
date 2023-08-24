class Solution
{
    public:
        int countTriplets(vector<int> &nums)
        {
            int result = 0;
            int n = nums.size();
            // // Iterate through all possible triples (i, j, k)
            // for (int i = 0; i < n; ++i)
            // {
            //     for (int j = 0; j < n; ++j)
            //     {
            //         for (int k = 0; k < n; ++k)
            //         {
            //             if ((nums[i] &nums[j] &nums[k]) == 0)
            //             {
            //                 result++;
            //             }
            //         }
            //     }
            // }
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mp[nums[i]&nums[j]]++;
                }
            }
            for(int i=0;i<n;i++){
                for(auto &it:mp){
                    if((nums[i]&it.first)==0){
                        result+=it.second;
                    }
                }
                
            }

            return result;
        }
};