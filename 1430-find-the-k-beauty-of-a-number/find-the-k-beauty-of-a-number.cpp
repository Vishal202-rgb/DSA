class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int count = 0;

        for (int i = 0; i <= n - k; i++) {
            string sub = s.substr(i, k);
            int val = stoi(sub);
            
            // Check if val is not zero and is a divisor of num
            if (val != 0 && num % val == 0) {
                count++;
            }
        }   
        return count;
    }
};