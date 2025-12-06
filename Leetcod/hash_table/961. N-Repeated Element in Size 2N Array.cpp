#include <vector>
#include <unordered_map>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        std::unordered_map<int,int>table;
        for(const int it : nums){
            table[it]++;
            if(table[it] * 2 == nums.size()) return it;
        }
        return 0;
    }
};

