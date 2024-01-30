class Solution {
private:
    bool isOperator(string c) {
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }
    int evaluate(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> temp;
        for (auto &it : tokens) {
            if (isOperator(it)) {
                int token1 = temp.back(); temp.pop_back();
                int token2 = temp.back(); temp.pop_back();
                int result = evaluate(token2, token1, it);
                temp.push_back(result);
            } else {
                temp.push_back(stoi(it));
            }
        }
        return temp[0];
    }
};