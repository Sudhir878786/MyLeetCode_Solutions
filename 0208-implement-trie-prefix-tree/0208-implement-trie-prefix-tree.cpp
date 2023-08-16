class Trie {
private: 
    struct Node{
      struct Node* child[26];
        bool isend=false;
    };
    
    Node* root;
public:
    
    Trie() {
       root=new Node(); 
    }
    
    void insert(string word) {
        Node*cur=root;
        for(auto it:word){
            if(cur->child[it-'a']==NULL){
                cur->child[it-'a']=new Node();
            }
            cur=cur->child[it-'a'];
        }
        cur->isend=true;
    }
    
    
    bool search(string word) {
        Node*cur=root;
        for(auto it:word)
        {
            if(cur->child[it-'a']==NULL){
                return false;
            }
            cur=cur->child[it-'a'];
        }
        if(cur->isend==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node*cur=root;
        for(auto it:prefix)
        {
            if(cur->child[it-'a']==NULL){
                return false;
            }
            cur=cur->child[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */