#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) 
    {
      if(s.size() == 1 && s[0] != ' ') return 1;
      
      size_t n = s.size() - 1;
      int begin = -1;
      int end = -1;
      
      for(size_t i = n; i >= 0; i--)
      {
          if(begin == -1 && s[i] != ' ')
          {
                begin = i;
          }
          else if(begin != -1 && s[i] == ' ')
          {
            end = i;
            return begin - end;
          }
          if(begin != -1 && i == 0)
          {
            return begin + 1;
          }
      }
      return 0;
    }
};