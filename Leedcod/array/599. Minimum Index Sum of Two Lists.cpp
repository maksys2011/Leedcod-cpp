#include <vector>
#include <string>
#include <map>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, 
    std::vector<std::string>& list2) {
        std::unordered_map<std::string, int>table;
        for(size_t i = 0; i < list1.size(); i++){
          if(!table.count(list1[i])) table[list1[i]] = i;
        }
        std::multimap<int, std::string>table1;
        for(int j = 0; j < list2.size(); j++){
          if(table.count(list2[j])){ 
            int key = table.at(list2[j]) + j;
            table1.insert({key,list2[j]});
          }
        }
        std::vector<std::string> str;
        int first_key = table1.begin()->first;
        auto range_pair = table1.equal_range(first_key);
        auto start = range_pair.first;
        auto stop  = range_pair.second;
         for (auto it = start; it != stop; it++) {
              str.push_back(it->second);
          }
        return str;
    }
};