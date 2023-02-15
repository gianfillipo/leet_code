/*
 * Problem components:
 *      Valid if is a isPalindrome
 *      string
 * Solution ideas:
 *  Two pointers
 *  
 * Time complexity:
 *      O(n)
 *  Space complexity:
 *      O(1)
 */


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++; continue;
            }
            if (!isalnum(s[right])) {
                right--; continue;
            }
            
            if (tolower(s[left]) != tolower(s[right]))
                return false;
        }

        return true;
    }
};

