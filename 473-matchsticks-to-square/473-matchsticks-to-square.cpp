class Solution {
public:
    bool dfs(vector<int>& matchsticks,int i,int sum1,int sum2,int sum3,int sum4,int target)
    {
      if(sum1>target || sum2>target || sum3>target || sum4>target) return false;// if any one of the sum is gret tthan target side  false
      if(i<0){    // if every side in matchsticks is visited 
        if(sum1==target && sum2==target && sum3==target && sum4==target) return true;
        else return false;
      }
      return dfs(matchsticks,i-1,sum1+matchsticks[i],sum2,sum3,sum4,target) || 
             dfs(matchsticks,i-1,sum1,sum2+matchsticks[i],sum3,sum4,target) ||
             dfs(matchsticks,i-1,sum1,sum2,sum3+matchsticks[i],sum4,target) ||
             dfs(matchsticks,i-1,sum1,sum2,sum3,sum4+matchsticks[i],target);
    }
  
  
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
      int par=0;
      for(int i=0;i<n;i++) par+=matchsticks[i]; // parameter 
      if(par%4!=0 || n<4)return false;   
      int target=par/4;  //target side for squares
      sort(matchsticks.begin(),matchsticks.end());   //sorting in accending to add side lower than target 
      int sum1=0,sum2=0,sum3=0,sum4=0;
      return dfs(matchsticks,n-1,sum1,sum2,sum3,sum4,target);
      
    }
};