class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(begin(asteroids),end(asteroids));
        long long MASS=mass;
        for(int &m:asteroids){
            if(MASS<m) return false;
            MASS+=m;
        }
        return true;
    }
};