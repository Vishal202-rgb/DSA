class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(begin(people),end(people));
        int res=0;

        int i=0,j=n-1;
        while(i<=j){
            if(people[j]+people[i]<=limit){
                i++;
                j--;
                res++;
            }else{
                j--;
                res++;
            }
        }
        return res;
    }
};