class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open=0;

        for(char ch:s){
            if(ch=='(' && open++ > 0) ans+=ch;
            if(ch==')' && open-- > 1) ans+=ch;
        }
        return ans;
    }
};