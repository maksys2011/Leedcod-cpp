#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int counter = 1;
        int first = 0;
        int second = 1;
        while (second <= nums.size() - 1) {
            if (nums[first] == nums[second]) 
            {
                second++;
            }
            else if (nums[first] < nums[second])
            {
                int tmp = nums[first + 1];
                nums[first + 1] = nums[second];
                nums[second] = tmp;
                first++;
                second++;
                counter++; 
            }
        }
        return counter;
    }
};