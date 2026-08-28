class Solution {
public:
    string res="";
    char midChar='$';
    int halfLength=0;
    int solve(string &curr,vector<int>&count,string &target,int i,bool greater){
        if(curr.length()==halfLength){
            string candidate=curr;
            string rightHalf=curr;
            reverse(begin(rightHalf),end(rightHalf));

            if(midChar!='$'){
                candidate+=midChar;
            }
            candidate+=rightHalf;
            if(candidate>target){
                res=candidate;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']==0) continue;

            if(!greater && ch<target[i]) continue;
            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater=greater||ch>target[i];
            if(solve(curr,count,target,i+1,isGreater)){
                return true;
            }
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        vector<int>count(26,0);

        for(char &ch:s){
            count[ch-'a']++;
        }
        int oddCount=0;
        for(int c=0;c<26;c++){
            if(count[c]%2==1){
                oddCount++;
                midChar=c+'a';
            }
        }
        if(oddCount>1) return "";

        for(int c=0;c<26;c++){
            count[c]/=2;
        }
        halfLength=n/2;


        string curr;
        solve(curr,count,target,0,false);
        return res;
    }
};