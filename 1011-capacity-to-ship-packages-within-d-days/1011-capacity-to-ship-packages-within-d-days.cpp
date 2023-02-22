class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int left=*max_element(w.begin(),w.end());
        int right=accumulate(w.begin(),w.end(),0);
        
        int ans=0;
        while(left<right){
            int cur=0;
            int mid=(left+right)/2;
            int count=1;
            for(auto x:w){
                if(cur+x>mid){
                    count++;
                    cur=0;
                }
                cur+=x;
                
            }
            if(count>d)left=mid+1;
            else right=mid;
        }
        return left;
    }
};