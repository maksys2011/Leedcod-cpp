#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        std::unordered_map<char,int>table;
        table['I'] = 1;
        // table['IV'] = 4;
        table['V'] = 5;
        // table['IX'] = 9;
        table['X'] = 10;
        // table['XL'] = 40;
        table['L'] = 50;
        // table['XC'] = 90;
        table['C'] = 100;
        // table['CD'] = 400;
        table['D'] = 500;
        // table['CM'] = 900;
        table['M'] = 1000;
        std::string result;
        while(num >= table['M']){
            result += 'M';
            num = num - table['M'];
        }
        while(num >= table['M'] - table['C']){
            result += 'C';
            result += 'M';
            num = num - (table['M'] - table['C']);
        }
        while(num >= table['D']){
            result += 'D';
            num = num - table['D'];
        }
        while(num >= table['D'] - table['C']){
            result += 'C';
            result += 'D';
            num = num - (table['D'] - table['C']);
        }
        while(num >= table['C']){
            result += 'C';
            num = num - table['C'];
        }
        while(num >= table['C'] - table['X']){
            result += 'X';
            result += 'C';
            num = num - (table['C'] - table['X']);
        }
        while(num >= table['L']){
            result += 'L';
            num = num - table['L'];
        }
        while(num >= table['L'] - table['X']){
            result += 'X';
            result += 'L';
            num = num - (table['L'] - table['X']);
        }
        while(num >= table['X'] - table['I']){
            result += 'I';
            result += 'X';
            num = num - (table['X'] - table['I']);
        }
        while(num >= table['V']){
            result += 'V';
            num = num - table['V'];
        }
        while(num >= table['V'] - table['I']){
            result += 'I';
            result += 'V';
            num = num - (table['V'] - table['I']);
        }
        while(num >= table['I']){
            result += 'I';
            num = num - table['I'];
        }
        return result;
    }
};
