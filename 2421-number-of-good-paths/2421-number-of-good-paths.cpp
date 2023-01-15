class Solution {
public:
     vector<bool> isactive;
    vector<int> parent;
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionDSU(int a, int b){
        int a1 = find(a), b1 = find(b);
        if(a1 == b1) return;
        parent[a1] = b1;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        isactive.resize(n, false);
        vector<vector<int>> graph(n);
        
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        map<int, vector<int>> mp;
        for(int i=0; i<n; ++i){
            mp[vals[i]].push_back(i);
        }
        
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
        
        int cnt = n;
        for(auto m : mp){
           for(auto &u : m.second){
               isactive[u] = true;
               for(auto &v : graph[u]){
                   if(isactive[v]) unionDSU(v, u);
               }
           } 
            
            unordered_map<int,int> freq;
            for(auto &u : m.second){
                int p = find(u);
                freq[p]++;
            }
            
            for(auto [key, val] : freq){
                cnt += (val*(val-1))/2;
            }
        }
        
        return cnt;
    }
};