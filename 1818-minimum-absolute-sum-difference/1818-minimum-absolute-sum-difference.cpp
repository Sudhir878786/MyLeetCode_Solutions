class Solution {
public:
     int MOD = 1e9+7;
    #define ll long long 
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int res = 0;
        vector<int > diff, temp;
        
        ll actualDiff = 0;
        
        for(int i=0; i<n; i++)
        {
            ll val = abs(nums1[i]-nums2[i]);
            diff.push_back(val);
            actualDiff += (val)%MOD;
        }
        
        // cout << actualDiff << endl;
        
        sort(nums1.begin(), nums1.end());
        
        for(int i=0; i<n; i++)
        {
            int j = lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
            cout<<"mid is"<<j<<endl;
            if(j == 0)        // i.e. j is the first index 
            {
                temp.push_back(abs(nums2[i]-nums1[j]));
            }
            
            else if(j == n)      // i.e. j is the last index 
            {
                temp.push_back(abs(nums2[i]-nums1[j-1]));
            }
            
            else 
            {
                int val = min(abs(nums2[i]-nums1[j-1]), abs(nums2[i]-nums1[j]));
                
                temp.push_back(val);
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            cout << temp[i] << " ";
            
            res = max(res, diff[i] - temp[i]);
        }
        
        cout << res << endl;
        
        int ans = (actualDiff - res + MOD) % MOD;
        
        return ans;
    }
};