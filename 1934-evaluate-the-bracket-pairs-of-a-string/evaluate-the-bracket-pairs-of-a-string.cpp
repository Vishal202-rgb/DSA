class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        unordered_map<string,string>mp;

        for(auto &x:knowledge){
            mp[x[0]]=x[1];
        }
        string res="";
        int i=0;

        while(i<n){
            if(s[i]=='('){
                int j=s.find(")",i+1);
                string temp=s.substr(i+1,j-i-1);
                res+=mp.count(temp)? mp[temp] :"?";
                i=j;
            }else{
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};