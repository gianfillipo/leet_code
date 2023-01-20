/*
    Problem components:
        Increment the large integer by one and return the resulting array of digits.
        
    Solution ideas:
        Check if the last values is different from 9, if it is, just increase
        by one and return digits
        If it is 9 turn the number to be 0
        If the program pass through the loop, it means all numbers are 9, then
        we create a new array with the size of the digits plus one, set the first
        element to be 1 and than return the new array
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {        
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }; 

            digits[i]=0;
        }

        vector<int> new_vector(n + 1);
        new_vector[0] = 1;
        return new_vector;
     }
};
