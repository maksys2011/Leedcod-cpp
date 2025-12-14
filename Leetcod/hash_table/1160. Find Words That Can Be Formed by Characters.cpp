#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::unordered_map<char, int>table;
       
        int result = 0;
        bool flag = true;
        for(char ch : chars){
            table[ch]++;
        }
        for(auto it : words){
            std::unordered_map<char,int>temp(table.begin(), table.end());
            flag = true;
            for(char ch : it){
                if(temp.count(ch)){
                    temp[ch]--;
                }else{
                    flag = false;
                    break;
                }
            }
            temp.clear();
            if(!flag) result += it.size();
        }
        return result;
    }
};

