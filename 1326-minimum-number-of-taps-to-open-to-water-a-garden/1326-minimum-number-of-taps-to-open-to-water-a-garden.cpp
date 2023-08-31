class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>arr(n+1,0);
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]==0){
                continue;
            }
            int left=max(0,i-ranges[i]);
            arr[left]= i+ranges[i];
        }
        // these we are calculating the starting(left) and ending(i+ranges) reach for each points 
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        int ans=0;
        // cout<<endl;
        int end=0,curstart=0;
        for(int i=0;i<=n;i++){
            if(i>end){
                return -1;
            }
            if(i>curstart){
                ans++;
                curstart=end;
            }
            end=max(end,arr[i]);
        }
        return ans;
    }
};