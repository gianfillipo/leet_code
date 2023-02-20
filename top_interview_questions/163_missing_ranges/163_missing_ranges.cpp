#include <stdio.h>
#include <vector>
#include <string>


/*
 * Problem components:
 *  nums vector
 *  lower and upper int limits
 *  You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

    A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

    Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

    Each range [a,b] in the list should be output as:

        "a->b" if a != b
        "a" if a == b
    
  Solution ideas
    Use prev as lower - 1 and curr as a member of nums or upper + 1;
    
    Time complexity:
        O(N)
    Space complexity:
        O(1)

 */

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int prev = lower - 1;

        for (int i = 0; i <= nums.size(); i++) {
            int curr = i < nums.size()? nums[i]: upper + 1; 

            if (prev + 1 <= curr - 1) res.push_back(format_range(prev + 1, curr - 1));
            
            prev = curr;
        }

        return res;
    }

    string format_range(int lower, int upper) {
        if (lower == upper) return to_string(lower);

        return to_string(lower) + "->" + to_string(upper);
    }
};

