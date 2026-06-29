class Solution {
public:
    string finalString(string s) {
        string res="";

        for(char &ch:s){
            if(ch!='i') res+=ch;
            else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};