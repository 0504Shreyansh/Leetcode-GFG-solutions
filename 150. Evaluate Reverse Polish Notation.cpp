/*
Concept -> Use a stack to store values and if any operator is encountered, just take out the the two top values,
and perform the operation, put back the result. At the end, you'll be left with the answer of the expression.
Hint -> Use long long so to avoid overflow problem
*/
bool operator(string s) {
        return (s=="+" || s=="-" || s=="*" || s=="/");
    }
    long long operation(string a, string b, string op) {
        long long x = stoi(a), y = stoi(b);
        if(op=="+") return y+x;
        else if(op=="-") return y-x;
        else if(op=="*") return (y*x);
        return y/x;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<string> s;
        for(string i:tokens) {
            if(operator(i)) {
                string aTop = s.top(); s.pop();
                string Top = s.top(); s.pop();
                long long res = operation(aTop,Top,i);
                s.push(to_string(int(res)));
            }
            else {
                s.push(i);
            }
           // cout << s.top() <<" ";
        }
        
        return stoi(s.top());
    }
