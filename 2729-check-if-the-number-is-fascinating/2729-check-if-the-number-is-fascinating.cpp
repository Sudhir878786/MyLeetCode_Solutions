class Solution {
public:
    bool isFascinating(int n) {
        int con1=2*n;
        int con2=3*n;
        map<char,int>mp;
        string tot= to_string(n)+to_string(con1)+to_string(con2);
        for(auto c:tot){
            mp[c]++;
        }
        sort(tot.begin(),tot.end());
        if(tot[0]=='0'){
            return false;
        }
        cout<<tot<<endl;
        for(auto it:mp){
            cout<<it.first<<"->"<<it.second<<endl;
            if(it.second>1){
                return false;
                break;
            }
            
        }
        return true;
        
    }
};