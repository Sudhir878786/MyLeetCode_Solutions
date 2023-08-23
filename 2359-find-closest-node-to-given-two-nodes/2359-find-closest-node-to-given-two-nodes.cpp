class Solution {
public:
    void dfs(vector<int>&edges,int node,vector<int>&d1,int d)
    {
        if(d1[node]!=-1){
            return;
        }
        d1[node]=d;
        if(edges[node]!=-1)
        {
            dfs(edges,edges[node],d1,d+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>d1(n,-1);
        vector<int>d2(n,-1);
        dfs(edges,node1,d1,0);
        dfs(edges,node2,d2,0);
        int node=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(d1[i]!=-1 and d2[i]!=-1){
                if(max(d1[i],d2[i])<ans){
                    ans=max(d1[i],d2[i]);
                    node=i;
                }
            }
        }
        return node;
    }
    
};