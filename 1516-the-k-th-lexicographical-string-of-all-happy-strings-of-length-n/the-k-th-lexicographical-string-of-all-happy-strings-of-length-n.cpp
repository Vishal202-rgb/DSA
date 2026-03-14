class Solution {
public:
    void solve(string curr,vector<string>&res,int n){
        if(curr.length()==n){
            res.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!curr.empty() && curr.back()==ch) continue;
            curr.push_back(ch);
            solve(curr,res,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
       string curr ="";
        vector<string>res;
        solve(curr,res,n);
        if(k>res.size()) return "";
        return res[k-1];
    }
};