class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeros = 1, ans = 0;
        for (int i = 0;i < flowerbed.size();i++) {
            if (flowerbed[i] == 0)
                ++zeros; 
            else {
                ans += (zeros - 1) / 2;
                zeros = 0;
            }
        }
        return ans + zeros / 2 >= n;
    }
};