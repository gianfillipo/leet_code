/*
 *  Problem components
 *      Find the maximum profit from a buy and sell operation
 *      Array
 *  
 *  Solution Ideas:
 *      Brute force (Bad solution)
 *      min number and max profit variables for o(n)
 *
 *  Time Complexity:
 *      O(n)
 *  Space Complexity:
 *      O(1)
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = pow(10, 4);
        int max_profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            else if (prices[i] - min > max_profit) {
                max_profit = prices[i] - min;
            }
        }

        return max_profit;
    }
};
