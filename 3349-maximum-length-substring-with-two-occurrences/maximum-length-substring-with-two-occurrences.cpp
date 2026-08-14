class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int left=0,ans=0;
        unordered_map<char,int>freq;

        for(int right=0;right<n;right++){
            freq[s[right]]++;

            while(freq[s[right]]>2){
                freq[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};