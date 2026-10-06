class Solution {
public:
    int minAddToMakeValid(string s) {
        int sz=0,open=0;

        for(char &c:s){
            if(c=='('){
                sz++;
            }else if(sz>0){
                sz--;
            }else{
                open++;
            }
        }
        return sz+open;
    }
};