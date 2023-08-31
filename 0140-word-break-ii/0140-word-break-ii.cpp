class Solution {
public:
    vector<string>ans;
    void func(string s, vector<string>&nums,set<string>&st,int ind,string temp)
    {
        if(ind==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            string cur=s.substr(ind,i-ind+1);
            // cout<<cur<<endl;
            if(st.find(cur)!=st.end()){
                func(s,nums,st,i+1,temp+cur+' ');
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& nums) {
        set<string>st(nums.begin(),nums.end());
        func(s,nums,st,0,"");
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};