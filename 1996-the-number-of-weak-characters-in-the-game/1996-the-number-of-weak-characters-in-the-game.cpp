class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[0]==b[0] ? a[1] > b[1] : a[0] < b[0] ;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop ) {
        
        int N = prop.size();
        int count  = 0 ;
        sort(prop.begin(),prop.end(),comp);
        vector<int>dp;
        int res = INT_MIN ;
        
        for(int i=N-1;i>=0;i--)
        {
            if(prop[i][1]<res)
                count++ ;
            res = max(res,prop[i][1]);
        }
        
        return count ;
    }
};