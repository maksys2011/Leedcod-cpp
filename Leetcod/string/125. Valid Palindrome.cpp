#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) 
    {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  for(size_t i = 0, j = s.size() - 1; i < j; )
  {
      if(isalnum(s[i]) && isalnum(s[j]))
      {
          if(s[i] != s[j])
        {
            return false;
        }
          else
        {
              i++;
              j--;
        }
      }else
      {
        if(!isalnum(s[i])) i++;
        if(!isalnum(s[j])) j--;
      }
  }
  return true;
}
};