class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0, high= letters.size()-1;
        char first=letters[0];
        while(low<=high){
            int mid= low+ (high-low)/2;
            if( int(letters[mid]) > int(target)){
                first= letters[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return first;
    }
};