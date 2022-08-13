class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();  
    int m = words[0].size() ;  
    
    vector<int>ans; 
    unordered_map<string,int>mpp;
    for(auto x : words){
        mpp[x]++;
    }
    
    int temp = n * m ; 
    int lastWindowIndex = s.size() - (temp) ; 
    
    for(int i = 0;i<=lastWindowIndex;i++){
        
        unordered_map<string,int>mp = mpp;
          int count = 0; 
        for(int j = 0;j<s.size();j++){
                
            string x = s.substr(i+j*m,m); 
            
            if(mp[x] == 0)
                break;
            else{
                mp[x]--;
                count++;
                
            }
        }
        if(count == n)
            ans.push_back(i);
  
    }
   
    return ans;
}
};