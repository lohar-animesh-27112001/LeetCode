class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int length = flowerbed.size();
        vector<int> tempFlowerbed = flowerbed;
        int temp = n;

        for (int i = 0; i < length; i++) {
            if (tempFlowerbed[i] == 0 &&
                (i == 0 || tempFlowerbed[i - 1] == 0) &&
                (i == length - 1 || tempFlowerbed[i + 1] == 0)) {
                tempFlowerbed[i] = 1;
                if (--temp == 0) return true;
            }
        }
        return false;
    }
};
