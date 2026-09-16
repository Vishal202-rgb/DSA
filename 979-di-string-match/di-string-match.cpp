class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int>res;
        int i=0,j=n;

        for(char &ch:s){
            if(ch=='I'){
                res.push_back(i++);
            }else{
                res.push_back(j--);
            }
        }
        res.push_back(i);
        return res;
    }
};