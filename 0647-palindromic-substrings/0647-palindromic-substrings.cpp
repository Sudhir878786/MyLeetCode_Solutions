class Solution {
public:
    bool ispal(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--]){
                return 0;
            }
        }
        return 1;
    }
    int countSubstrings(string s) {
        vector<string>ans;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
           for(int j=1;j<=n-i;j++){
               if(ispal(s.substr(i,j))){
                   ans.push_back(s.substr(i,j));
               }
           }
        }
        return ans.size();
    }
};