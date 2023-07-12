class MedianFinder {
public:
    priority_queue<int> s, g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        int top = s.top();
        s.pop();
        g.push(-top);
        if(g.size() > s.size()) {
            int top = -g.top();
            g.pop();
            s.push(top);
        }
    }
    
    double findMedian() {
        return (s.size() != g.size()) ? s.top() 
            : (1.0 * (s.top() - g.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */