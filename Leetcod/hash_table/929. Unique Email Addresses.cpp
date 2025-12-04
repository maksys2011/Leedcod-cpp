#include <vector>
#include <string>
#include <set>

class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
      std::set<std::string>table_email;
      std::string email;
      std::string str1;
      for(auto it : emails){
        char tmp{};
        for(int i = 0; i < it.size(); i++){
          if(it[i] == '@') tmp = '@';
          if(it[i] == '+' && tmp != '@'){
            tmp = '@';
            while(it[i] != '@') i++;
          }
          if(tmp != '@' && std::isalpha(it[i])) str1 += it[i];
          else if(tmp == '@') str1 += it[i];
        }
        table_email.insert(str1);
        str1.clear();
      }
        return table_email.size();
    }
};