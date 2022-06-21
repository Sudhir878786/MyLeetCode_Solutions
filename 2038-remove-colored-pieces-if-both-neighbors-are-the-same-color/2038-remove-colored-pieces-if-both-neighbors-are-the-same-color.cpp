class Solution {
public:
    bool winnerOfGame(string c) {
        if(c.size()<3)return false;
      int a=0,b=0;
      for (int i=0;i<c.size()-2;i++) {
        if(c.substr(i,3)=="AAA") a++;
        else if(c.substr(i,3)=="BBB") b++;
        
      }
      if(a>b) return true;
      return false;
    }
};