class Solution {
public:
    vector<string>ans;
    void func(string digits,string &cur,int ind,vector<string>&let)
    {
        if(ind==digits.size()){
            ans.push_back(cur);
            return;
        }
        string temp=let[digits[ind]-'0'];
        for(int i=0;i<temp.size();i++){
            cur.push_back(temp[i]);
            func(digits,cur,ind+1,let);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> let={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())
            return {};
        string cur="";
        func(digits,cur,0,let);
        return ans;
       
    }
};