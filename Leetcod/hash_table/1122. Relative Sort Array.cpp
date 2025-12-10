#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int,int>table;
        for(auto it : arr1) table[it]++;
        std::vector<int>result;
        for(auto it : arr2){
            if(table.count(it)){
                int i = table[it];
                while(i > 0){
                    result.push_back(it);
                    i--;
                }
                table.erase(it);
            }
        }
        std::vector<int>tmp;
        for(auto it : table){
            int i = it.second;
            while(i > 0){
                tmp.push_back(it.first);
                i--;
            }
        }
        std::sort(tmp.begin(), tmp.end());
        for(auto it : tmp){
            result.push_back(it);
        }
        return result;
    }
};

