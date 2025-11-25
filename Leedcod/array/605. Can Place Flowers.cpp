#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(n == 0) return true;
        if(size == 1 && flowerbed[0] == 0 && n == 1) return true;
        if(size == 1 && flowerbed[0] == 1 && n == 1) return false;
        if(size == 1 && flowerbed[0] == 1 && n == 0) return true; 
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                if (i - 1 >= 0 && i + 1 < size) {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if (i - 1 < 0) {
                    if(i + 1 < size && flowerbed[i + 1] == 0){
                    flowerbed[i] = 1;
                    n--;}
                }
                else if (i + 1 == size) {
                    if(i - 1 > 0 && flowerbed[i - 1] == 0){
                    flowerbed[i] = 1;
                    n--;}
                }
            }
            if (n == 0) break;
        }
        return n == 0;
    }  
};