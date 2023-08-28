class MyStack {
public:
    queue<int> q, qq;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while (q.size() > 1) {
            qq.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        while (qq.size()) {
            q.push(qq.front());
            qq.pop();
        }
        return ans;
    }
    
    int top() {
        while (q.size() > 1) {
            qq.push(q.front());
            q.pop();
        }
        int ans = q.front();
        qq.push(q.front());
        q.pop();
        while (qq.size()) {
            q.push(qq.front());
            qq.pop();
        }
        return ans;
    }
    
    bool empty() {
        return (q.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */