class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            if(!isalpha(s[left])){
                left++;
            }else if(!isalpha(s[right])){
                right--;
            }else{
                char temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;
    }
};