class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long base = 1000;
        long long c = 1;

        while(base <= n) {
            long long next = base * 1000 - 1;

            if(next > n)
                next = n;

            ans += (next - base + 1) * c;

            base = base * 1000;
            c++;
        }

        return ans;
    }
};