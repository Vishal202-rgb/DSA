class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
            return true;
        return false;
    }
    long long countVowels(string word) {
        int n=word.size();
        long long int ans=0;
        vector<long long int> dp;
 
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp.push_back(n);
            else
                dp.push_back((n - i) + dp[i - 1] - i);
        }
        for (int i = 0; i < n; i++)
            if(isVowel(word[i]))
                ans += dp[i];
        return ans;
    } 
};