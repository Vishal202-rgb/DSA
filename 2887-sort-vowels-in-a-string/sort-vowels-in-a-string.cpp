class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>vowels = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char>extractedVowels;

        for (char &ch:s) {
            if (vowels.count(ch)) {
                extractedVowels.push_back(ch);
            }
        }
        sort(begin(extractedVowels),end(extractedVowels));

        string res= "";
        int vowelIndex=0;
        for (char &ch:s) {
            if (vowels.count(ch)) {
                res.push_back(extractedVowels[vowelIndex++]);
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};