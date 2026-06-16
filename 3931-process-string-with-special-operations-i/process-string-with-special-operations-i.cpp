class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char &ch:s){
            if(ch=='*'){
                if(res.length()>0) res.pop_back();
            }else if(ch=='#'){
                res+=res;
            }else if(ch=='%'){
                reverse(begin(res),end(res));
            }else{
                res+=ch;
            }
        }
        return res;
    }
};