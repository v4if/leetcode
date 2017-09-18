//
// Created by root on 9/18/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * */

using namespace std;

namespace best_time_to_buy_and_sell_stock2 {
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); ++i) {
            int maxProfit = 0;
            for (int j = 0; j < i; ++j) {
                if (prices[i] > prices[j]) {
                    maxProfit = dp[j] + prices[i] - prices[j];
                }
            }
            dp[i] = max(dp[i - 1], maxProfit);
        }

        return dp[prices.size() - 1];
    }
}

TEST(leetcode, leetcode_best_time_to_buy_and_sell_stock2__Test) {
    using namespace best_time_to_buy_and_sell_stock2;
    vector<int> prices{1, 4, 7};
    cout << maxProfit(prices) << endl;
}