class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int prod=1;
            n=num;

            while(n){
                prod*=n%10;
                n/=10;
            }
            if(prod%t==0) break;
            else
                num++;
        }
        return num;
    }
};