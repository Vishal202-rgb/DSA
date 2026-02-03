class Solution {
public:
   int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(string &email : emails) {
        string cleanEmail;
        for(char ch : email) {
            if(ch == '+' || ch == '@') break;
            if(ch == '.') continue;
            cleanEmail += ch;
        }
        cleanEmail += email.substr(email.find('@'));
        st.insert(cleanEmail);
    }
    return st.size();
  }
};