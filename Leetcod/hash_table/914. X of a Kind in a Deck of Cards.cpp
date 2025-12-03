#include <iostream>
#include <vector> 
#include <unordered_map>

class Solution {
public:
    bool hasGroupsSizeX(std::vector<int>& deck) {
        std::unordered_map<int, int>table{};
        for(auto it : deck){
            table[it]++;
        }
        int result = gcbArray(table);
        return result >= 2;
    }
    int gcd(int a, int b){
        while(b != 0){
           int tmp = b;
           b = a % b;
           a = tmp;
        }
    }
    int gcbArray(const std::unordered_map<int, int>& table){
        int result = 0;
        for(const auto& it : table){
            result = gcd(result, it.second);
        }
        return result;
    }
};
