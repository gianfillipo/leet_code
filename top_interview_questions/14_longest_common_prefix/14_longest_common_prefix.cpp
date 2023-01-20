/*
 *  Problem components:
 *      List of string
 *      Find the prefix between them
 *
 *  Solution ideas:
 *      The ans will be the first string substring to index of the common prefix
 *      Note that strings doen't get out of index error in c++
 *      We can compare all the string to the first one and then chose least index
 *      between all, that will be used in the subtring.
 *
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = strs[0].length(), n = strs.size(); 

        for (int i = 1; i < n; i++) {
            int j = 0;
            
            while (j < strs[i].length() and strs[i][j] == strs[0][j]) j++;

            ans = min(ans, j);
        }

        return strs[0].substr(0, ans);
    }
};

