class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        unordered_map<char,int>mp;
        
        for(int i =0;i<chars.size();i++){
            if(mp.find(chars[i])!=mp.end()) mp[chars[i]]++;
            else{
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second==1){
                    s+=it->first;
                }
                else{
                    s+=it->first+to_string(it->second);
                }
                
            }
            mp.clear();
            mp[chars[i]]++;
            }   
        }
         for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second==1){
                    s+=it->first;
                }
                else{
                    s+=it->first+to_string(it->second);
                }
                
            }
        chars.clear();
        for(int i=0;i<s.size();i++){
            chars.push_back(s[i]);
        }
        return chars.size();
    }
};