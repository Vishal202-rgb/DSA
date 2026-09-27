class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack = {""};

        for (char ch : s) {
            if (ch == '(') {
                stack.push_back("");
            }
            else if (ch == ')') {
                string temp = stack.back();
                stack.pop_back();

                reverse(temp.begin(), temp.end());
                stack.back() += temp;
            }
            else {
                stack.back() += ch;
            }
        }
        return stack[0];
    }
};