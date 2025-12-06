#include <vector>
#include <unordered_map> 

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::unordered_map<int,int>table1{};
        std::unordered_map<int,int>table2{};
        int possible_judge = -1;
        for(size_t i = 0; i < trust.size(); i++){
            table1[trust[i][1]]++;
            table2[trust[i][0]]++;
        }
        for(auto it : table1){
            if(it.second == n - 1){
                possible_judge = it.first;
            }
        }
        if(table2.count(possible_judge)) return -1;
        return possible_judge;
        }              
};
