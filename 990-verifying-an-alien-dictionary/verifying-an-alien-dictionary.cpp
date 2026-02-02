class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>index(26,0);
        int n=order.size();
        for(int i=0;i<n;i++){
            index[order[i]-'a']=i;
        }
        for(int i=0; i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            for(int j=0;j<w1.size();j++){
                if(j==w2.size())return false;
                if(w1[j]!=w2[j]){
                    if(index[w2[j]-'a']<index[w1[j]-'a']){
                    return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};