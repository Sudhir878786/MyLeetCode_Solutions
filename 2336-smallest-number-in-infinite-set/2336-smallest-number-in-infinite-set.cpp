class SmallestInfiniteSet {
public:
    set<int>ans;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            ans.insert(i);
        }
    }
    
    int popSmallest() {
        int sm=*ans.begin();
        ans.erase(sm);
        return sm;
    }
    
    void addBack(int num) {
        ans.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */