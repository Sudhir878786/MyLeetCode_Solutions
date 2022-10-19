class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        vector<pair<float,int>>v;
        float d=0;
       for(int i=0;i<points.size();i++){
           int x=points[i][0];
           int y=points[i][1];
           d=sqrt(x*x + y*y);
           v.push_back({d,i});
           
       }
        sort(v.begin(),v.end());
        for(auto it:v){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i=0;i<k;i++){
            ans.push_back({points[v[i].second][0],points[v[i].second][1]});
        }
        return ans;
    }
};