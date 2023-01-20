/*  Problem components:
 *      Array of numbers
 *      Find two numbers to get a target
 *      Only one Solution
 *      Return the answer in any order
 *
 *  Solution ideas:
 *      Create a hash table to store the values as we pass through them
 *      Use a complement that is the number that added to the current number
 *      will result in the target
 *      Check if we had pass through that number using the hash table
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> helper;
        int complement;

        for (int i = 0; i < nums.size(); i++) {
            complement = target - nums[i];

            if (helper.find(complement) != helper.end()) {
                return {i, helper[complement]};
            }
            else {
                helper[nums[i]] = i;
            }
        } 

        return {-1, -1};
    }
};

