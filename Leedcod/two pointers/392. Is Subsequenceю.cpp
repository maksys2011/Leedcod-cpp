#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) 
    {
        int ptr_s = 0;
        int ptr_t = 0;
        while(ptr_s < s.size())
        {
          if(s[ptr_s] == t[ptr_t]){
            ptr_s++;
            ptr_t++;
          }else{
            if(ptr_t < t.size()){
              ptr_t++;
            }else{
              return false;
            }
          }
        } 
        return true;
    }
};