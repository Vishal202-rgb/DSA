class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_set<char>st;
        int ans=0;

        for(char &ch:s){
            if(st.count(ch)){
                ans+=2;
                st.erase(ch);
            }else{
                st.insert(ch);
            }
        }
        if(!st.empty()){
            ans++;
        }
        return ans;
    }
};