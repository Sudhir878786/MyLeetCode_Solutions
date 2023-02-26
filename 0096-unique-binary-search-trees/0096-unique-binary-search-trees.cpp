class Solution {
public:// if n->is the root then  its left ie n->left = has i-1 node and node->right=n-i node   
    // so total possilbe is i-1+1+n-i;  
    
    /*     (1)
		  /   \
	 (i - 1)  (n - i) */
    
    int numTrees(int n) {
      
        // if(n<=1 )return 1;
        // int ans=0;
        // for(int i=1;i<=n;i++){
        //     ans+=numTrees(i-1)*numTrees(n-i);
        // }
        // return ans;
        
        
        // another approach  O(n) and space O(1)
        
        // as total BST posssible = for each node (i-1)*(n-i);
        // C(N) = C(0)C(N-1) + C(1)C(N-2) +………+ C(i-1)C(N-i) +………….+ C(N-1)C(0).
        
        long double ans = 1;
	for (int k = 2; k <= n; k++)
		ans *= (n + k), ans /= k;
	return ans;
    }
};