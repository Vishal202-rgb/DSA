class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>cell(m,string(n,'#'));

        if(m==1||n==1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cell[i][j]='.';
                }
            }
            return cell;
        }
        for(int j=0;j<n;j++){
            cell[0][j]='.';
        }
        for(int i=0;i<m;i++){
            cell[i][n-1]='.';
        }
        return cell;
    }
};