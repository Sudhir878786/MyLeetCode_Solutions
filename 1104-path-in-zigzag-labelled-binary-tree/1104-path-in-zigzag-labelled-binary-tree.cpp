class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
      
      vector<int>v;
      int l=floor(log2(label))+1;
      while(l--){
        v.push_back(label);
        int end=pow(2,l);
        int dif=(label-end)/2+1;
        label=end-dif;
      }
      reverse(v.begin(),v.end());
      return v;
              
        
    }
};