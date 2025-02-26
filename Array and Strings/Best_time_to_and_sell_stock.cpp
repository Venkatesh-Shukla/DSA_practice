/*
Problem: Best Time to Buy and Sell Stock

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and a different day to sell it in the future.

Return the maximum profit you can achieve from this transaction. If no profit is possible, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No transactions can yield a positive profit.

Constraints:
- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

Follow-up: Could you solve this problem in O(n) time?
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int sell_day = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            maxi = max(maxi, sell_day - prices[i]);
            if (sell_day < prices[i]) {
                sell_day = prices[i];
            }
        }
        return maxi;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    cout << "Max Profit: " << solution.maxProfit(prices) << endl;
    
    return 0;
}

/*
Solution Approach:

1. Traverse the array from right to left, keeping track of the maximum future selling price (`sell_day`).
2. Calculate the profit for each day if we were to buy at that price and sell at `sell_day`.
3. Keep track of the maximum profit encountered.
4. If a new maximum price is found, update `sell_day`.
5. Runs in O(n) time and O(1) space.
*/
