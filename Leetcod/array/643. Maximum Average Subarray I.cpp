#include <iostream>
#include <vector>

class Solution {
  public:
        double findMaxAverage(std::vector<int>& nums, int k) {
            int n = nums.size();
            double maximum_aberage{};
            double sum = 0;
            for(size_t i = 0; i < k; i++){
              sum += nums[i];  
            }
            maximum_aberage = sum;
            for(size_t i = k; i < n; i++){
              sum += nums[i] - nums[i - k];
              maximum_aberage = std::max(maximum_aberage, sum);
            }
            
            return maximum_aberage / k;
        }
};
