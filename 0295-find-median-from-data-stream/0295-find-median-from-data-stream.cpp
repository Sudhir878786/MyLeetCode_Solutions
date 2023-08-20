class MedianFinder {
public:
    priority_queue<int>maxx;
    priority_queue<int,vector<int>,greater<int>>minn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxx.empty()|| maxx.top()>num){
            maxx.push(num);
        }
        else{
            minn.push(num);
        }
        if(maxx.size()>minn.size()+1){
            minn.push(maxx.top());
            maxx.pop();
        }
        else if(maxx.size()+1<minn.size()){
            maxx.push(minn.top());
            minn.pop();
        }
    }
    
    double findMedian() {
        if(minn.size()==maxx.size()){
            return (maxx.top()+minn.top())/2.0;
        }
        else {
            if(minn.size()>maxx.size()){
                return minn.top();
            }
            else{
                return maxx.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */