#include <vector>
#include <set>


class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) 
  {
      std::set<int>sq1;
      std::set<int>sq2;
      std::set<int>sq3;
      std::set<int>line;
      std::vector<std::set<int>>column(9);
      for(size_t i = 0; i < board.size();i++)
      {
        if(i == 3){
          sq1.clear();
          sq2.clear();
          sq3.clear();
        }
        if(i == 6){
          sq1.clear();
          sq2.clear();
          sq3.clear();
        }
        
        for(size_t j = 0; j < board[i].size(); j++)
        {
          char ch = board[i][j];
          int tmp{};
          if(ch - '0' != -2){
            tmp = ch - '0';
          }else{
            continue;
          }
          if(line.count(tmp)){ 
            return false;}
          else line.insert(tmp);
          
          if(column[j].count(tmp)){
            return false;} 
          else column[j].insert(tmp);
          
            if(j < 3){
              if(sq1.count(tmp)) return false;
              else sq1.insert(tmp);
            }
            if(j > 2 && j < 6){
              if(sq2.count(tmp)) return false;
              else sq2.insert(tmp);
            }
            
            if(j > 5){
              if(sq3.count(tmp)) return false;
              else sq3.insert(tmp);
            }
          }
        
        line.clear();
      }
      return true;
  }
};