/*
   Problem components:
    Elements
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

   Solution ideas:
    Use hash map to store elements;
 */

#include <vector>
#include <unordered_map>
using namespace std;

/*Time complexity: O(N)
Space complexity: O(1)*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> res;
        int max = INT_MIN, num;

        for(int i = 0; i < nums.size(); i++){
            if (res.find(nums[i]) == res.end()){
                res[nums[i]] = 0;
            }

            res[nums[i]] += 1;
        }

        for (auto& it : res) {
            if (it.second > max) {
                max = it.second;
                num = it.first;
            }
        }

        return num;
    }
};

/* Boyer-Moore Voting Algorithm
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate;

        for(int i = 0; i < nums.size(); i++) {
            if (count == 0) candidate = nums[i];
            
            count += candidate == nums[i] ? 1 : -1;
        }

        return candidate;
    }
};
