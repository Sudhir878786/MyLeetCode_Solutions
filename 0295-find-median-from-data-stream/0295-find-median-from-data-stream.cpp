class MedianFinder {
public:
    priority_queue<int>small,big;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        big.push(-small.top());
        small.pop();
        if(small.size()<big.size()){
            small.push(-big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>big.size()){
            return small.top();
        }
        else{
            return (small.top() - big.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */