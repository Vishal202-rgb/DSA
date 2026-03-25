class Solution {
public:
    int countDigitOne(int n) {
    int count = 0;

    for (long long i= 1;i<=n;i*=10) {
        int a = n/i, b = n%i;
        count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }
    return count;
    }
};