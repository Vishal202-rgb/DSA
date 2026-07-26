class Solution {
public:
    char solveOp(char op, vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';
        if (op == '&') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
        if (op == '|') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';
    
        return 't'; // Unreachable
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') continue;

            if (expression[i] == ')') {
                vector<char> values;
                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator
                st.push(solveOp(op, values));
            } else {
                st.push(expression[i]);
            }
        }
        return (st.top() == 't');
    }
};