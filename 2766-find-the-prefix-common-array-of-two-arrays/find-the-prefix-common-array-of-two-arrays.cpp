class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int ct=0;

        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]){
                mp[A[i]]+=2;
                ct++;
            }else{
                mp[A[i]]++;
                mp[B[i]]++;
                if(mp[A[i]]==2) ct++;
                if(mp[B[i]]==2) ct++;
            }
            A[i]=ct;
        }
        return A;
    }
};