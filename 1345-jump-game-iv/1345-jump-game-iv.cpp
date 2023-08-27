class Solution {
public:
    // we will create all the possible cordinate in map;
    
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
            /*
            100 -> 0,4
            -23 -> 1,2
            404 -> 3,9
            23  -> 5,6,7
            3   -> 8
            */
        }
            queue<int>q;
            q.push(0);
            vector<bool>vis(n+1,false);
            vis[0]=true;
            int ans=0;
            while(!q.empty()){
                int s=q.size();
                for(int i=0;i<s;i++){
                    auto cur=q.front();
                    q.pop();
                    if(cur==n-1){
                        return  ans;
                    }
                    // case 1 can move cur-1;
                    if(cur-1>=0 and !vis[cur-1] ){
                        vis[cur-1]=true;
                        q.push(cur-1);
                    }
                    // case 2 cur+1
                    if(cur+1<n and !vis[cur+1]){
                        vis[cur+1]=true;
                        q.push(cur+1);
                    }
                    // case 3 arr[i]==arr[j];
                    for(auto v:mp[arr[cur]]){
                        // cout<<v<<endl;
                        if(!vis[v]){
                            vis[v]=true;
                            q.push(v);
                        }
                    }
                    mp.erase(arr[cur]);
                }
                ans++;
            }
        return -1;
        
    }
};