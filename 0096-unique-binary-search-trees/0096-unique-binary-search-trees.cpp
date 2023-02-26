class Solution {
public:// if n->is the root then  its left ie n->left = has i-1 node and node->right=n-i node   
    // so total possilbe is i-1+1+n-i;  
    
    /*     (1)
		  /   \
	 (i - 1)  (n - i) */
    
    int numTrees(int n) {
      
        if(n<=1 )return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};