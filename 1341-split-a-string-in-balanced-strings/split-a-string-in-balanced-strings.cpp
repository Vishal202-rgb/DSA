class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int count=0;

        for(char c:s){
            if(c=='L'){
                count++;
            }else{
                count--;
            }
            if(count==0) ans++;
        }
        return ans;
    }
};