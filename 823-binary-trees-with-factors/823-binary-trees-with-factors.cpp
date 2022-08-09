class Solution {
public:
    
    #define MOD 1000000007
    #define ll long long
    
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        ll ans = 0;
        
        unordered_map<ll,ll> mp;
        
        sort(arr.begin(),arr.end());
        
        
        for(int i=0;i<arr.size();i++)
        {
            // leaf node
            ll curr_ans  = 1;
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j])
                    continue;
                
                ll num1 = arr[j];
                ll num2 = arr[i]/arr[j];
                
                curr_ans = (curr_ans+(mp[num1]*mp[num2])%MOD)%MOD;
            }
            
            mp[arr[i]] = curr_ans;
            
            ans = (ans+curr_ans)%MOD;
        }
        
        return ans;
    }
};