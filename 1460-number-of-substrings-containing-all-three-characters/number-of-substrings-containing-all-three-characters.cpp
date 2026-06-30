class Solution {
public:
    int numberOfSubstrings(string s) {
        int la=-1,lb=-1,lc=-1;
        int total=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                la=i;
            }else if(s[i]=='b'){
                lb=i;
            }else{
                lc=i;
            }
            if(la!=-1 && lb!=-1 && lc!=-1){
                total+=min({la,lb,lc})+1;
            }
        }
        return total;
    }
};