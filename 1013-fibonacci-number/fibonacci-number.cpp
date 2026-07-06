class Solution {
public:
    int fib(int n) {
        //Approach-1 (Recursion)
        if(n<=1) return n;
         return fib(n-1)+fib(n-2);
    }
};