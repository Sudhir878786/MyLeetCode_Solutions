// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
//         unordered_map<int,int>mp;
//         priority_queue<int>q;
//         int ans=0;
//         int remove=0;
//         for(auto it:arr){
//             mp[it]++;
//         }
//         for(auto x : mp){
//             q.push(x.second);
//         }
//         while(remove<arr.size()/2){
//             remove+=q.top();
//             q.pop();
//             ans++;
//         }
//         return ans;
        
        
//     }
// };



class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        int c=0,ans=0;
        multiset<int,greater<int>>m;
        for(auto it : arr){
            mp[it]++;
        }
        for(auto x : mp){
            m.insert(x.second);
        }
        for(auto i=begin(m);c<arr.size()/2;i++){
            ans++;
            c+=*i;
        }
        return ans;
        
        
    }
};