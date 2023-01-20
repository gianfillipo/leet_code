/*
Problem components
    * Given an array of numbers whose length is a power of 2
    * If numbers.size() == 1 end the process
    * For every even index i where 0 <= i < n / 2, assign the value of newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
    * For every odd index i where 0 <= i < n / 2, assign the value of newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
    * Replace the array nums with newNums.
    * Repeat the entire process starting from step 1.
    * Return the last number that remains in nums after applying the algorithm.


Solution ideas
    * Check if the size is 1 and return nums[0]
    * Create the new array and use recursion with that new array
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int new_nums_size = nums.size() / 2;
        vector<int> new_nums(new_nums_size);

        for (int i = 0; i < new_nums_size; i++) {

            if (i % 2 == 0) {
                new_nums[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
            else {
                new_nums[i] = max(nums[2 * i] , nums[2 * i + 1]);
            }
        }

        return minMaxGame(new_nums);
    }
};
