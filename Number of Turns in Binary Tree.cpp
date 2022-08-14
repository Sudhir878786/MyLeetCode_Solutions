
class Solution{
  public:
    // function should return the number of turns required to go from first node to second node
    Node*LCA(Node*root,int f,int s)
    {   // function for lCA 
        if(root==NULL)
           return root;
        if(root->data==f || root->data==s)
           return root;
           
        Node*l=LCA(root->left,f,s);
        Node*r=LCA(root->right,f,s);
        
        if(l!=NULL and r!=NULL)
           return root;
           
        if(l!=NULL)
           return l;
           
        return r;   
    }
    void path(Node*root,int d,string str,string&s)
    {
        if(root==NULL)
          return;
        if(root->data==d){
            s=str;
        }
        path(root->left,d,str+"l",s);
        path(root->right,d,str+"r",s);
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      // we need to find the lowest common ancesctor of first and second node ;
      // base case 
      if(root==NULL||first==second)
          return 0;
      Node*lc=LCA(root,first,second);   
      string s1="",s2="";  // string so that we can find path from lc to first and second node;
      path(lc,first,"",s1);  // path from lc -> first node
      path(lc,second,"",s2);  //  path from lc -> second node
      reverse(s1.begin(),s1.end());  // reverse the  path from lc -> first node and add in s1
      s1+=s2;
      int ans=0;
      int f=0;
      for(int i=0;i<s1.length()-1;i++){
          if(s1[i]!=s1[i+1]){
              f=1;
              ans++;
          }
      }
      if(f==0)
        return -1;
      return ans;
    }
};
