class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>p;
        for(int i=0;i<profits.size();i++){
            p.emplace_back(capital[i],profits[i]);
        
        }
        sort(p.begin(),p.end());
//         for(int i=0;i<p.size();i++){
           
//         cout<<p[i].first<<p[i].second<<endl;
//         }
        
        
        priority_queue<int> q;
        int j=0;
        for(int i=0;i<k;i++){
            while(j<profits.size() and p[j].first<=w){
                q.push(p[j++].second);
            }
            if(q.empty())break;
            w+=q.top();
            q.pop();
        }
        return w;
    }
};