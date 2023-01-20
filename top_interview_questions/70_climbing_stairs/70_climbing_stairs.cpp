/*
    Problem components:
       You are climbing a staircase. It takes n steps to reach the top.
       Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
       Binary decision.

    Solution ideas:
        One possible solution to this problem is thinking as a binary search where we can either go one or two steps. 
            
            * Brute force recursion
            * Time complexity: O(2**n)
            * Space complexity O(n)
            
            Lets suppose we have we have 3 steps to reach the top
                            0
                          1   2
                        2  3 3 4
                       3 4
                       **TOTAL: 3 posibilities**
            We could use a recursion brute forse solution that won't be so efficient and it might exceed time limite
            where time complexity will be o(2**n) and O(n) space complexity.

            * Recursion with memoization 
            * Time complexity: O(n)
            * Space complexity: O(n)
            
            Instead of doing redundant processing, we could store the result of the processing and return the array element
            whenever we find a previous calculation result.

            * Dynamic progamming
            * Time complexity: O(n)
            * Space complexity: O(n)

            Starting with the elements 1 and 2 the nth number will be the sum of the last
            two elements, so we could use Dynamic programming to solve this problem
            [1, 2, 3, 5]

            * Fibonacci solution:
            * Time complexity: O(n)
            * Space compexity: O(1)
                As we can see the posibilites the number of steps is n+1th fibonacci number  
*/

class Solution {
public:
    int climbStairs(int n) {
        int i = 1, j = 1;

        for (int k = 0, k < n - 1; k++) {
            i = i + j;
            j = i - j;
        }

        return i;     
    }
};

