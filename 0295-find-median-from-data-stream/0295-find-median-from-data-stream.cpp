class MedianFinder {
public:
    priority_queue<int> s, g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        int top = s.top();
        s.pop();
        g.push(-1*top);
        // try to equalise the number of vals in both the pqs
        if(g.size() > s.size()) {
            top = g.top();
            g.pop();
            s.push(-1*top);
        }
    }
    
    double findMedian() {
        if(g.size()==s.size())
            return (s.top()-g.top())/2.0;
        return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */