class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int cnt=0,res=0;
        int i=0;

        while(i<n){
            if(s[i]=='('){
                cnt++;
                i++;
            }else{
                if(cnt>0){
                    cnt--;
                }else{
                    res++;
                }
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                }else{
                    res++;
                    i++;
                }
            }
        }  
        return res+cnt*2;
    }
};