#include <iostream>
#include <vector>

// 1,0,0,1,0 - ?

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        /*if(size == 1 && flowerbed[0] == 0 && n == 1) return true;
        if(size == 1 && flowerbed[0] == 1 && n == 1) return false;
        if(size == 1 && flowerbed[0] == 1 && n == 0) return true;  */
        int res = 0;
        int counter = 1;
        for(size_t i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                if(i - 1 < 0){
                    if(i + 1 < size && flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                    if(i + 1 >= size){
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                if(i - 1 > 0 && flowerbed[i - 1] == 0){
                                        if(i + 1 < size && flowerbed[i + 1] == 0){
                        flowerbed[i] = 1;
                        n--;
                    }
                    if(i + 1 >= size){
                        flowerbed[i] = 1;
                        n--;
                    }

                }
            }
   
        }
        return n == 0;
    }
};

int main()
{
    Solution s;
    std::vector<int>nums{1,0,0,0,0};
    std::cout << s.canPlaceFlowers(nums, 2);
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}