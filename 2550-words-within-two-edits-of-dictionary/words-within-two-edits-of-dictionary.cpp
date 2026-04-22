class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].length();
        vector<string>res;

        for(string &q:queries){
            for(string &d:dictionary){
                int diff=0;

                for(int i=0;i<n;i++){
                    if(q[i]!=d[i]) {
                        diff++;
                    }
                    if(diff>2) break;
                }
                if(diff<=2){
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};