class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
       
        for(int i=0;i<points.size()-1;i++){
             unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                double xdif=x2-x1;
                double ydif=y2-y1;
                if(y1==y2){
                    mp[90]++;
                }else{
                    double slope=(double)(xdif/ydif);
                    mp[slope]++;
                }
                
                
            }
             int t=0;
        for(auto it:mp){
            t=max(t,it.second+1);
            cout<<it.first<<"->"<<it.second<<endl;
           
        }
             ans=max(ans,t);
        }
       
        return ans;
    }
};