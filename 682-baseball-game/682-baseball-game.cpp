class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
      for(int i=0;i<ops.size();i++){
        if(ops[i]=="D")
        {
          int x=ans.back()*2;
            ans.push_back(x);
        }
        else if(ops[i]=="C")
        {
          ans.pop_back();
        }
        else if (ops[i]=="+")
        {
          int z=ans.end()[-1]+ans.end()[-2];
          ans.push_back(z);
        }
        else {
          ans.push_back(stoi(ops[i]));
        }
      }
      int sum= accumulate(ans.begin(),ans.end(),0);
      return sum;
    }
};