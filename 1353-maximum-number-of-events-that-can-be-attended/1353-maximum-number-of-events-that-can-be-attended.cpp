class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(e.begin(),e.end());
        for(int i=0;i<e.size();i++){
            cout<<e[i][0]<<e[i][1]<<" ";
        }
        cout<<endl;
        int start=e[0][0];   // start date
        int end=INT_MIN; 
        for(int i=0;i<e.size();i++){
           end=max(end,e[i][1]);   // end date
        }
        int i=0;
        int ans=0;
        for(int d=start;d<=end;d++){
            while(i<e.size()  and d==e[i][0]){
                pq.push(e[i][1]);
                i++;
            }
            
            while(!pq.empty() and d>pq.top()){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};