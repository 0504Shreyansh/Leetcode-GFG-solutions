class MyQueue {
private:
    vector<int> arr;
    int i, j;
public:
    MyQueue() {
        i = 0, j = 0;
    }
    
    void push(int x) {
        arr.push_back(x);
        j++;
    }
    
    int pop() {
        return arr[i++];
    }
    
    int peek() {
        return arr[i];
    }
    
    bool empty() {
        return (i == j);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */