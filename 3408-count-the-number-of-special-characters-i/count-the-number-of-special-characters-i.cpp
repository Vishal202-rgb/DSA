class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>mp(begin(word),end(word));
        int cnt=0;

        for(char ch='a';ch<='z';ch++){
            if(mp.count(ch) && mp.count(ch-'a'+'A')){
                cnt++;
            }
        }
        return cnt;
    }
};