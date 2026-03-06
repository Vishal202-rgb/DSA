class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero = false;

        for(char c : s){
            if(c == '0') zero= true;
            if(c == '1' && zero) return false;
        }
        return true;
    }
};