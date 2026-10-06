class Solution {
public:
    int minSwaps(string s) {
        int sz=0;

        for(char &ch:s){
            if(ch=='['){
                sz++;
            }else if(sz>0){
                sz--;
            }
        }
        return (sz+1)/2;
    }
};