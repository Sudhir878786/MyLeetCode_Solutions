class Solution {
public:
    vector<string>ans;
    void func(int i,int j,string s,int n)
    {
        if(s.size()==2*n){
            ans.push_back(s);
            return ;
        }
        if(i<n){
            func(i+1,j,s+'(',n);
        }
        if(j<i){
            func(i,j+1,s+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        func(0,0,"",n);
        return ans;
    }
};