class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        vector<int>ans;
        int i=0,j=n;

        for(char &ch:s){
            if(ch=='I'){
                ans.push_back(i++);
            }else{
                ans.push_back(j--);
            }
        }
        ans.push_back(i);
        return ans;
    }
};