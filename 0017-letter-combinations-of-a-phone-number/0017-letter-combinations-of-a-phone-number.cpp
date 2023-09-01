class Solution {
public:
    vector<string>ans;
    void func(string digits,int ind,vector<string>&let,string temp)
    {
        if(ind==digits.size()){
            ans.push_back(temp);
            return;
        }
        string cur=let[digits[ind]-'0'];
        // cout<<cur<<endl;
        for(int i=0;i<cur.size();i++){
            temp.push_back(cur[i]);
            func(digits,ind+1,let,temp);
            temp.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
         vector<string> let={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits==""){
            return {};
        }
         func(digits,0,let,"");
        return  ans;

    }
};