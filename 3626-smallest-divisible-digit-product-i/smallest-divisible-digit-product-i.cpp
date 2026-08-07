class Solution {
public:
    int findDigit(int num){
        int prod=1;
        while(num){
            prod*=(num%10);
            num/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int num=n;num<=n+10;num++){
            if(findDigit(num)%t==0) return num;
        }
        return -1;
    }
};