class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int zeros = 1;

        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                zeros++;
            } 
            else {
                count += (zeros - 1) / 2;
                zeros = 0;
            }
        }

        zeros++;
        count += (zeros - 1) / 2;

        return count >= n;
    }
};