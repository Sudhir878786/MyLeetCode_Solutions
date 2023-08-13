class Solution {
public:
   bool rotateString(string s, string goal) {
        
       if(s==goal){
           return true;
       }
        int n=s.size();
       string s2=s;
       for(int i=0;i<n;i++){
          char left=s2[0];
           s2=s2.substr(1,n+1);
           s2=s2+left;
           if(s2==goal){
               return true;
           }
       }
       return false;
        
    }
};