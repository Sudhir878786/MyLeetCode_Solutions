class Solution {
public:
    int minPartitions(string n) {
        int ans=*max_element(n.begin(),n.end())-'0';
      return ans;
    }
};