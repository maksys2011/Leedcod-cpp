#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) 
    {
        if(needle.empty()) return -1;
        int h = 0;
        int n = 0;
        int index = 0;
        while(h < haystack.size())
        {
          index = h;
          while(h < haystack.size() && n < needle.size() && haystack[h] == needle[n])
          {
              h++;
              n++;
              if(n == needle.size()) return index;   
          }
          h = index + 1;;
          n = 0;
        }
        return - 1;
    }
};