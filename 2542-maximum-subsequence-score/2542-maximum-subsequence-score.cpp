class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={nums2[i],nums1[i]};
        }
        long long ans=0;
        sort(v.begin(),v.end());
        long long s=0;
   
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=n-1;i>=0;i--){
            pq.push(v[i].second);
            s+=v[i].second;
            if(pq.size()>k){
                s-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                 // cur=s*v[i].second;
                ans=max(ans,s*v[i].first);
            }
            
        }
        return ans;
    }
};