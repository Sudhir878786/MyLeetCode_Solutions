class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>p;
      int i=0,dif=0;
      for( i=0;i<heights.size()-1;i++){
        dif=heights[i+1]-heights[i];
        if(dif<=0){
          continue;
          
        }
        bricks-=dif;
        p.push(dif);
        if(bricks<0){
          bricks+=p.top();
          p.pop();
          ladders--;
        }
        if(ladders<0) break;
      }
      return i;
    }
};