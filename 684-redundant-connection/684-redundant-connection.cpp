class Solution {
public:
  int find(int n,vector<int>p){
    if(n==p[n]) return n;
    return find(p[n],p);
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int>par(edges.size()+1,0);
        for(int i=0;i<par.size();i++){
            par[i]=i;
        }
                                                                     
          vector<int>ans;
          for(auto e:edges){
           int a=e[0],b=e[1];
            int p1=find(a,par);
            int p2=find(b,par);
            if(p1==p2)ans=e;
             par[p1]=p2;
          }
     
      
    return ans;
                         
            
                                                                     
                                                                     

                                                                     
                                                                     
        
    }
};