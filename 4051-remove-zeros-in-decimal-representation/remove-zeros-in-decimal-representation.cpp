class Solution {
public:
    long long removeZeros(long long n) {
        string temp = to_string(n);
        long long ans = 0;
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] != '0'){
                ans = ans * 10 + temp[i] - '0';
            }
        }
        return ans;
    }
};