/*  Problem components:
 *      String of roman numbers
 *      Convert them to an decimal integer
 *      Each character represent a numbers
 *      The order of the string result in different numbers
 *
                Symbol       Value
                I             1
                V             5
                X             10
                L             50
                C             100
                D             500
                M             1000
 *      
 *  Solution ideas:
 *      Iterate through the string
 *      Create a hash table where each key is a character that points to an
 *      integer
 *      Depending on the order of the string the number could turn into negative
 *      We don't need to worry about out of index, since the hash table will return
 *      -1 in case the key doesn't exist.
 *
*/


#include <unordered_map>;
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_integer {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int size_string = s.size();
        int result = 0;

        for (int i = 0; i < size_string; i++) {
            if(roman_integer[s[i]] >= roman_integer[s[i+1]]) {
                result += roman_integer[s[i]];
            }
            else {
                result -= roman_integer[s[i]];
            }
        }

        return result;
    }
};
