#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        if(words.size() <= 1) return true;
        std::unordered_map<char, int>alien_alphabet;
        for(int i = 0; i < order.size(); i++){
          alien_alphabet[order[i]] = i + 1;}
        for(size_t i = 0; i < words.size() - 1; i++){
          if(!string_comparison(words[i], words[i + 1], alien_alphabet)){
            return false;
          }
        }  
        return true;
    }
    bool string_comparison(const std::string str1, const std::string str2, 
                            std::unordered_map<char, int>& table){
        for(size_t i = 0, j = 0; i < str1.size() && j < str2.size(); i++, j++)
        {
            char ch1 = str1[i];
            char ch2 = str2[i];
            
            if(ch1 != ch2){
              return table[ch1] < table[ch2];
            }
        }
      return str1.size() <= str2.size();
    }
};