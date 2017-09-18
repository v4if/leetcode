//
// Created by root on 9/18/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 * */

using namespace std;

namespace best_time_to_buy_and_sell_stock {
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int maxProfit = 0;
        int minBuy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > minBuy) {
                maxProfit = max(prices[i] - minBuy, maxProfit);
            }

            minBuy = min(prices[i], minBuy);
        }

        return maxProfit;
    }
}

TEST(leetcode, leetcode_best_time_to_buy_and_sell_stock__Test) {
    using namespace best_time_to_buy_and_sell_stock;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}