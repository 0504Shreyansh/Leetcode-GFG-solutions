class BrowserHistory {
public:
    int size = 5001;
    vector<string> history;
    int i, last;
    BrowserHistory(string homepage) {
        history.resize(5001);
        history[0] = homepage;
        i = 0, last = 0;
    }
    
    void visit(string url) {
        if (history[i] != url) {
            history[++i] = url;
            last = i;
        }
    }
    
    string back(int steps) {
        i = max(i - steps, 0);
        return history[i];
    }
    
    string forward(int steps) {
        i = min(i + steps, last);
        return history[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */