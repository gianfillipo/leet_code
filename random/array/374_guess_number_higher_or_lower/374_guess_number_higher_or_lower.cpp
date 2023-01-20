/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * long int guess(long int num);
 */

/**
Problem components:
    * Find a target number
    * The numbs are obviously in a sequence
    * Using an external function that returns a value

Solution ideas:
    * Use binary search to find the number
    * Use the given number as the right variable
    * If it breaks through the loop then return either left or right
*/


class Solution {
public:
    long int guessNumber(long int n) {
        long int left = 0;
        long int right = n;
        long int mid;

        while (left < right) {
            mid = (left + right) / 2;

            if (guess(mid) == 0) {
                return mid;
            }

            else if (guess(mid) == -1) {
                right = mid - 1;
            }
            
            else {
                left = mid + 1;
            }
        }
    return left;
    }
};
