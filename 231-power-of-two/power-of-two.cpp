class Solution {
public:
    bool isPowerOfTwo(int n) {
        // for(int i=0;i<=30;i++){
        //     int ans=pow(2,i);
        //     if(ans==n){
        //         return true;
        //     }
        // }
        // return false;
        if(n==1) return true;
        if(n<=0||n%2!=0) return false;

        return isPowerOfTwo(n/2);
    }
};